#include <bits/stdc++.h>
#define mp make_pair
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

    int P, Q, L, R;
    while (cin >> P >> Q >> L >> R) {
        vector<int> a(P), b(P);
        vector<int> c(Q), d(Q);
        forn(i, P) cin >> a[i] >> b[i];
        forn(i, Q) cin >> c[i] >> d[i];
        int ans = 0;
        fore(t, L, R) {
            forn(q, Q) {
                bool ok = false;
                forn(p, P) if (0 <= min(d[q]+t,b[p])-max(c[q]+t,a[p])) {
                    ok = true;
                    break;
                }
                if (ok) {
                    ++ans;
                    break;
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
