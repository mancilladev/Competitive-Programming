#include <bits/stdc++.h>
#define fi first
#define se second
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()
#define deb(x) cout << #x << " = " << x << endl
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define fore(i, l, r) for (int i = (int)(l); i <= (int)(r); ++i)
#define ford(i, n) for (int i = (int)(n) -1; i >= 0; --i)

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int main (void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n, m, x, y;
    const int INF = 1e9 + 7;
    while (cin >> n >> m >> x >> y) {
        vector<int> cb(m+1, 0), cw(m+1, 0);
        for1(i, n) {
            string s; cin >> s;
            for1(j, m) {
                if (s[j-1] == '#') ++cb[j];
                else ++cw[j];
            }
        }
        int preb[m+7][m+7], prew[m+7][m+7];
        memset(preb, 0, sizeof preb);
        memset(prew, 0, sizeof prew);
        for1(l, m) {
            fore(r, l, m) {
                prew[l][r] += prew[l][r-1] + cw[r];
                preb[l][r] += preb[l][r-1] + cb[r];
            }
        }

        int dp[2][m+7];
        memset(dp, INF, sizeof dp);
        dp[0][0] = dp[1][0] = 0;
        for1(i, m) {
            fore(a, x, y) {
                if (i - a < 0) continue;
                dp[0][i] = min(dp[0][i], dp[1][i-a]+prew[i-a+1][i]);
                dp[1][i] = min(dp[1][i], dp[0][i-a]+preb[i-a+1][i]);
            }
        }
        cout << min(dp[0][m], dp[1][m]) << '\n';
    }
    return 0;
}
