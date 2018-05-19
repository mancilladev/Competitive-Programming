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
#define FOR(i, a, b) for (int i(a); i < b; ++i)
#define REP(i, n) FOR (i, 0, n)
#define FORD(i, a, b) for (int i(a); i >= b; --i)

const int MN = 2e5 + 7;
int N, S;

int main (void) {
    while (cin >> N >> S) {
        vector<int> fl(S + 1, 0);
        REP(i, N) {
            int f, t;
            cin >> f >> t;
            fl[f] = max(fl[f], t);
        }
        int ans = fl[S];
        FORD(i, S-1, 0) {
            ans = max(fl[i], ans + 1);
        }
        cout << ans << '\n';
    }
    return 0;
}
