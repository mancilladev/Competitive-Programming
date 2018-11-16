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

    int n;
    vector<int> c {-1, 0, 1};
    const int INF = 1e9 + 7;
    while (cin >> n) {
        vector<int> arr(n);
        forn(i, n) cin >> arr[i];
        if (n <= 2) {
            cout << 0 << '\n';
            continue;
        }

        int d = INF;
        function<int(int,int,int)> dfs = [&](int x, int lst, int cnt) {
            if (x == n) return cnt;
            int res = INF;
            forn(i, 3) {
                int t = arr[x] + c[i];
                if (x == 1) d = t - lst;
                else if (d != t - lst) continue;
                res = min(res, dfs(x+1, t, cnt + (c[i] != 0)));
            }
            return res;
        };

        int ans = INF;
        forn(i, 3) {
            d = INF;
            ans = min(ans, dfs(1, arr[0]+c[i], c[i] != 0));
        }
        cout << (ans == INF ? -1 : ans) << '\n';
    }
    return 0;
}
