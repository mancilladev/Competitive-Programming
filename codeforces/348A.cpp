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

    ll n;
    while (cin >> n) {
        vector<ll> arr(n);
        ll m = 0, sum = 0;
        forn(i, n) {
            cin >> arr[i];
            sum += arr[i];
            m = max(m, arr[i]);
        }

        function<bool(ll)> ok = [&](ll games) {
            ll arbitreado = 0;
            forn(i, n) arbitreado += games - arr[i];
            return arbitreado >= games;
        };

        ll ans = m-1;
        for (ll k = sum; k > 0; k>>=1) {
            while (ans + k <= sum && !ok(ans + k))
                ans += k;
        }
        cout << ans + 1 << '\n';
    }
    return 0;
}
