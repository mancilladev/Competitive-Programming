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
        ll a = 0, b = 0;
        while (4 * a <= n) {
            b = (n - 4 * a) / 7;
            if (4 * a + 7 * b == n) {
                break;
            }
            ++a;
        }
        if (4 * a + 7 * b == n) {
            forn(i, a) cout << 4;
            forn(i, b) cout << 7;
            cout << '\n';
        } else {
            cout << -1 << '\n';
        }
    }
    return 0;
}
