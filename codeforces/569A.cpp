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
int T, S, q;

int main (void) {
    while (cin >> T >> S >> q) {
        int current = 0, ans = 1;
        while (S < T) {
            current += q;
            S += q - 1;
            if (S >= T) break;
            if (current >= S) {
                current = 0;
                ++ans;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
