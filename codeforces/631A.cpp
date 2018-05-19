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
        vector<int> arr(N), brr(N);
        REP(i, N) cin >> arr[i];
        REP(i, N) cin >> brr[i];
        int ans = 0;
        REP(i, N) {
            int sa = 0, sb = 0;
            FOR(j, i, N) {
                sa |= arr[j];
                sb |= brr[j];
            }
            ans = max(ans, sa + sb);
        }
        cout << ans << '\n';
    }
    return 0;
}
