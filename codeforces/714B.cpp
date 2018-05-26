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
    const int INF = 1e9 + 7;
    while (cin >> N) {
        vector<int> arr(N);
        int mini = INF, maxi = 0;
        forn(i, N) {
            cin >> arr[i];
            maxi = max(maxi, arr[i]);
            mini = min(mini, arr[i]);
        }
        function<bool(int)> solves = [&](int n) {
            int x = -1;
            for (auto it : arr) {
                if (it == n) continue;
                if (x == -1) {
                    x = abs(it - n);
                } else if (x != abs(it - n)) {
                    return false;
                }
            }
            return true;
        };
        int res = mini;
        for (int k = (maxi - mini)>>1; k > 0; k >>= 1) {
            while (res + k <= maxi && solves(res + k))
                res += k;
        }
        cout << (solves(res) ? "YES" : "NO") << '\n';
    }
    return 0;
}
