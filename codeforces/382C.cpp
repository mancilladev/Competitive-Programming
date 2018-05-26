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
        bool equal = true;
        for1(i, n-1) if (arr[0] != arr[i]) equal = false;
        if (equal && n != 1) {
            cout << 1 << '\n' << arr[0] << '\n';
            continue;
        }
        if (n == 1) {
            cout << -1 << '\n';
        } else if (n == 2) {
            int d = abs(arr[0] - arr[1]);
            if (d == 0) {
                cout << 1 << '\n';
                cout << arr[0] << '\n';
            } else if (d%2 == 0) {
                cout << 3 << '\n';
                cout << arr[0] - d << ' ';
                cout << arr[0] + d/2 << ' ';
                cout << arr[1] + d << '\n';
            } else {
                cout << 2 << '\n';
                cout << arr[0] - d << ' ' << arr[1] + d << '\n';
            }
        } else {
            vector<int> d;
            forn(i, n-1) d.push_back(abs(arr[i] - arr[i+1]));
            sort(all(d));
            d.erase(unique(all(d)), d.end());
            if (sz(d) == 1) {
                cout << 2 << '\n';
                cout << arr[0] - d[0] << ' ';
                cout << arr.back() + d[0] << '\n';
            } else if (sz(d) == 2 && d[1] == d[0] * 2) {
                int ok = 1;
                int res = -1;
                forn(i, n-1) if (arr[i] + d[1] == arr[i+1]) {
                    --ok;
                    res = arr[i] + d[0];
                }
                if (ok < 0) cout << 0 << '\n';
                else cout << 1 << '\n' << res << '\n';
            } else {
                cout << 0 << '\n';
            }
        }
    }
    return 0;
}
