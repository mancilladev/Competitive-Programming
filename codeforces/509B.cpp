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

    int n, k;
    const int INF = 1e9 + 7;
    while (cin >> n >> k) {
        vector<int> arr(n);
        int mini = INF, maxi = -INF;
        forn(i, n) {
            cin >> arr[i];
            mini = min(mini, arr[i]);
            maxi = max(maxi, arr[i]);
        }
        if (maxi - mini > k) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        int m = mini;
        forn(i, n) {
            int cur = 1;
            forn(j, arr[i]) {
                if (j > m) ++cur;
                cout << cur << ' ';
            }
            cout << '\n';
        }
    }
    return 0;
}
