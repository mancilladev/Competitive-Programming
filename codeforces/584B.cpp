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

const int MOD = 1e9 + 7;
int N;

int main (void) {
    while (cin >> N) {
        ll res = 1;
        REP(i, 3 * N) {
            res *= 3;
            res %= MOD;
        }
        ll minus = 1;
        REP(i, N) {
            minus *= 7;
            minus %= MOD;
        }
        res = (res - minus) % MOD;
        if (res < 0) res += MOD;
        cout << res << '\n';
    }
    return 0;
}
