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

    int n, m;
    const int MOD = 1e9 + 7;
    while (cin >> n >> m) {
        vector<set<char>> v(m);
        forn(i, n) {
            string s; cin >> s;
            forn(j, m) v[j].insert(s[j]);
        }
        ll ans = sz(v[0]);
        for1(j, m-1) {
            int cnt = sz(v[j]);
            ans *= cnt;
            ans %= MOD;
        }
        cout << ans << '\n';
    }
    return 0;
}
