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
#define mp make_pair
#define fi first
#define se second
#define FOR(i, a, b) for (int i(a); i < b; ++i)
#define REP(i, n) FOR (i, 0, n)
#define FORD(i, a, b) for (int i(a); i >= b; --i)

const int MN = 2e5 + 7;
double PI = acos(-1);
int N;

int main (void) {
    while (cin >> N) {
        vector<double> arr(N);
        REP(i, N) cin >> arr[i];
        sort(all(arr));
        double ans = 0;
        REP(i, N) {
            if (i%2 == N%2) continue;
            double area = PI * sq(arr[i]);
            double rem = (i > 0 ? PI * sq(arr[i-1]) : 0);
            ans += area - rem;
        }
        cout << fixed << setprecision(10) << ans << '\n';
    }
    return 0;
}
