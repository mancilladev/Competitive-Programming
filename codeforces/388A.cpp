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
    while (cin >> n) {
        vector<int> arr(n);
        forn(i, n) cin >> arr[i];
        sort(all(arr));
        function<bool(int)> solves = [&](int k) {
            int cur = 0;
            int h = 0;
            while (cur < n) {
                if (arr[cur++] < h)
                    return false;
                if (cur % k == 0) {
                    ++h;
                }
            }
            return true;
        };
        int ans = 100;
        for1(i, 100) {
            if (solves(i)) {
                ans = i;
                break;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
