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

    int n, m;
    while (cin >> n >> m) {
        vector<int> arr(n);
        forn(i, n) {
            cin >> arr[i];
        }
        sort(all(arr));

        vector<ll> pre(n+1);
        forn(i, n) {
            pre[i] = arr[i-1];
            if (i != 0)
                pre[i] += pre[i-1];
        }

        function<bool(int,int)> check = [&](int i, int q) {
            if (i-q < 0) return false;
            return 1LL * arr[i] * q - (pre[i] - pre[i-q]) <= 1LL * m;
        };
        function<int(int)> maxcount = [&](int i) {
            int x = 0;
            for (int k = n; k > 0; k>>=1) {
                while (x+k < n && check(i, x+k))
                    x += k;
            }
            return x + 1;
        };
        pii ans {0, 0};
        forn(i, n) {
            int mc = maxcount(i);
            if (mc > ans.fi) ans = make_pair(mc, arr[i]);
        }

        cout << ans.fi << ' ' << ans.se << '\n';
    }
    return 0;
}
