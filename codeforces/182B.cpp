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
    ios::sync_with_stdio(false), cin.tie(0);
    cout.precision(10), cout << fixed;

    int d, n;
    while (cin >> d >> n) {
        ++d;
        vector<int> arr(n);
        forn(i, n) cin >> arr[i];
        int ans = 0;
        int cur = 1;
        for (auto m : arr) {
            if (cur != 1) {
                ans += d - cur;
                cur = 1;
            }
            cur = m + 1;
            cur %= d;
            if (cur == 0) cur = 1;
        }
        cout << ans << '\n';
    }
    return 0;
}
