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

ll C(ll n) {
    // k == 2
    return n * (n-1) / 2;
}

int main (void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n, d;
    while (cin >> n >> d) {
        vector<int> arr(n);
        forn(i, n) cin >> arr[i];
        ll ans = 0;
        int r = 0;
        forn(l, n) {
            r = max(r, l+1);
            while (r < n && abs(arr[r] - arr[l]) <= d) {
                ++r;
            }
            ans += C(r-l-1);
        }
        cout << ans << '\n';
    }
    return 0;
}
