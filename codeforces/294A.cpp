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
int N, M, a[MN];

void shoot (int x, int y) {
    int l = x - 1;
    int r = a[y] - x;
    a[y] = 0;
    a[y-1] += l;
    a[y+1] += r;
}

int main (void) {
    while (cin >> N) {
        FOR(i, 1, N+1) {
            cin >> a[i];
        }
        cin >> M;
        REP(i, M) {
            int x, y;
            cin >> y >> x;
            shoot(x, y);
        }
        FOR(i, 1, N+1) cout << a[i] << '\n';
    }
    return 0;
}
