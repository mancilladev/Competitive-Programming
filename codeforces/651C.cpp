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

const int MN = 20 + 7;
int N, M, a[MN][MN];

void changeCols (int c1, int c2) {
    FOR(i, 1, 1+N) {
        swap(a[i][c1], a[i][c2]);
    }
}

bool test () {
    FOR(i, 1, 1+N) {
        int diff = 0;
        FOR(j, 1, 1+M) {
            if (a[i][j] != j)
                ++diff;
        }
        if (diff > 2)
            return false;
    }
    return true;
}

bool solve () {
    if (test())
        return true;
    FOR(c1, 1, 1+M) FOR(c2, c1+1, 1+M) {
        changeCols(c1, c2);
        if (test())
            return true;
        changeCols(c1, c2);
    }
    return false;
}

int main (void) {
    while (cin >> N >> M) {
        FOR(i, 1, 1+N) FOR(j, 1, 1+M) {
            cin >> a[i][j];
        }
        cout << (solve() ? "YES" : "NO") << '\n';
    }
    return 0;
}
