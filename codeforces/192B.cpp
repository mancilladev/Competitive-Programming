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

    int N;
    while (cin >> N) {
        vector<pii> arr(N);
        forn(i, N) {
            cin >> arr[i].fi;
            arr[i].se = i+1;
        }
        sort(all(arr));

        int ans = 0;
        vector<bool> usable(N+7, true);
        for (auto p : arr) {
            usable[p.se] = false;
            ans = p.fi;
            bool ok = true;
            for1(i, N) {
                if ((i == 1 || i == N) && !usable[i]) {
                    ok = false;
                }
                if (!usable[i+1] && !usable[i+2]) {
                    ok = false;
                }
            }
            if (ok) ++ans;
            else break;
        }
        cout << ans << '\n';
    }
    return 0;
}
