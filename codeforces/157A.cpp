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

const int MN = 30 + 7;
int N, a[MN][MN];

int main (void) {
    while (cin >> N) {
        memset(a, 0, sizeof a);
        vector<int> sx(N), sy(N);
        REP(i, N) REP(j, N) {
            cin >> a[i][j];
            sx[j] += a[i][j];
            sy[i] += a[i][j];
        }
        int res = 0;
        REP(i, N) REP(j, N) {
            res += (sx[j] > sy[i]);
        }
        cout << res << '\n';
    }
    return 0;
}
