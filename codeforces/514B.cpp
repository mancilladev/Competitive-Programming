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
typedef pair<double,double> pdd;

int main (void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n;
    double x0, y0;
    while (cin >> n >> x0 >> y0) {
        vector<pii> arr(n);
        forn(i, n) {
            cin >> arr[i].fi >> arr[i].se;
            arr[i].fi -= x0;
            arr[i].se -= y0;
        }
        int ans = 0;
        vector<bool> vis(n);
        forn(i, n) {
            if (vis[i]) continue;
            ++ans;
            vis[i] = true;
            pii p = arr[i];
            forn(j, n) {
                if (vis[j]) continue;
                pii q = arr[j];
                if (q.se * p.fi == q.fi * p.se)
                    vis[j] = true;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
