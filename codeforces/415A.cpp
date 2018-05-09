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

const int MN = 100 + 7;
int N, M, b[MN];

int main (void) {
    while (cin >> N >> M) {
        memset(b, 0, sizeof b);
        FOR(i, 1, 1+M) {
            int x;
            cin >> x;
            FOR(i, x, N+1) if (b[i] == 0) b[i] = x;
        }
        FOR(i, 1, N+1)
            cout << b[i] << ' ';
        cout << '\n';
    }
    return 0;
}
