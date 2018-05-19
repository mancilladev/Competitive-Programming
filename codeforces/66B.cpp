#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#ifdef LOCAL
#define deb(x) cout << #x << " = " << x << endl
#else
#define deb(x) 0
#endif
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()
#define sq(x) (x) * (x)
#define fi first
#define se second
#define FOR(i, a, b) for (int i(a); i < b; ++i)
#define REP(i, n) FOR (i, 0, n)
#define FORD(i, a, b) for (int i(a); i >= b; --i)

const int MN = 2e5 + 7;
int N;

int main (void) {
    while (cin >> N) {
        vector<int> arr(N), d(N);
        REP(i, N) cin >> arr[i];
        REP(i, N) {
            int l = i, r = i;
            while (l > 0 && arr[l-1] <= arr[l])
                --l;
            while (r < N-1 && arr[r+1] <= arr[r])
                ++r;
            d[i] = r - l + 1;
        }
        int ans = *max_element(all(d));
        cout << ans << '\n';
    }
    return 0;
}
