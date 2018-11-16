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

ll s (ll x) {
    ll res = 0;
    while (x) {
        res += x % 10;
        x /= 10;
    }
    return res;
}

ll f (ll x, ll sx) {
    return x * (x + sx);
}

int main (void) {
    ios::sync_with_stdio(false), cin.tie(0);
    cout.precision(10), cout << fixed;

    ll n;
    while (cin >> n) {
        forn(sx, 91) {
            ll ans = 0;
            for (ll k = sqrt(n); k > 0; k >>= 1) {
                while (f(ans + k, sx) <= n)
                    ans += k;
            }
            if (f(ans, sx) == n && s(ans) == sx) {
                cout << ans << '\n';
                break;
            }
            if (sx == 90) {
                cout << -1 << '\n';
            }
        }
    }
    return 0;
}
