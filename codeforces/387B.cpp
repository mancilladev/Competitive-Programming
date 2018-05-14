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
int N, M;

int main (void) {
    while (cin >> N >> M) {
        vector<int> a(N), b(M);
        REP(i, N) cin >> a[i];
        REP(i, M) cin >> b[i];
        sort(all(a));
        sort(all(b));
        int p = 0;
        int res = 0;
        REP(i, N) {
            while (p < M && b[p] < a[i])
                ++p;
            if (p < M && a[i] <= b[p]) {
                ++p;
                continue;
            }
            ++res;
        }
        cout << res << '\n';
    }
    return 0;
}
