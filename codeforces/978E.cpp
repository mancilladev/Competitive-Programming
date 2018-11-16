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

    int n, w;
    while (cin >> n >> w) {
        vector<int> arr(n);
        ll low = 0, up = 0, cur = 0;
        forn(i, n) {
            int x; cin >> x;
            cur += x;
            low = min(low, cur);
            up = max(up, cur);
        }
        ll l = -1, r = -1;
        for (ll k = w; k > 0; k >>= 1) {
            while (l+k <= w && (l+k)+low < 0)
                l += k;
        }
        for (ll k = w; k > 0; k >>= 1) {
            while (r+k <= w && (r+k)+up <= w)
                r += k;
        }
        cout << max(0LL, r-l) << '\n';
    }
    return 0;
}
