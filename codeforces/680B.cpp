#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = (int)1e9 + 7;
#define deb(x) cerr << #x << " = " << x << endl
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()
#define sq(x) (x) * (x)
#define fi first
#define se second
#define UNIQUE(a) sort(all(a)), (a).erase(unique(all(a)), (a).end())
#define FOR(i, a, b) for (int i(a); i < b; ++i)
#define REP(i, n) FOR (i, 0, n)
#define FORD(i, a, b) for (int i(a); i >= b; --i)

const int MN = 2e5 + 7;
int N, K;

int main (void) {
    while (cin >> N >> K) {
        vector<int> a(N);
        REP(i, N) cin >> a[i];
        --K;

        int ans = 0;
        REP(i, N) {
            int l = K - i;
            int r = K + i;
            bool cl = (l >= 0 && a[l]);
            bool cr = (r < N && a[r]);
            if (cl && cr)
                ans += (l == r ? 1 : 2);
            else if (cl || cr)
                ans += (l < 0 || r >= N);
        }
        cout << ans << '\n';
    }
    return 0;
}
