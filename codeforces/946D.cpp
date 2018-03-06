#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
const int INF = (int)1e9 + 7;

#define deb(x) cerr << #x << " = " << x << endl
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()
#define sq(x) (x) * (x)
#define pb push_back
#define f first
#define s second
#define endl '\n'

#define UNIQUE(a) sort(all(a)), (a).erase(unique(all(a)), (a).end())
#define FOR(i, a, b) for (int i(a), b_(b); i < b_; ++i)
#define REP(i, n) FOR (i, 0, n)
#define FORD(i, a, b) for (int i(a), b_(b); i >= b_; --i)

const int N = 1007;
int n, m, k, dp[N][N];
char c;
vector<vector<int>> t(N);

int f(int d, int y) {
    if (y > k) return INF;
    if (d == n) return 0;
    if (dp[d][y] != -1) return dp[d][y];

    auto l = t[d].begin();
    auto r = t[d].end();
    --r;

    if (y == k) return dp[d][y] = *r - *l + 1 + f(d+1, y);

    int res = min(*r - *l + 1 + f(d+1, y), f(d+1, y + sz(t[d])));
    int i = 0;
    while (++i, (++l) != t[d].end()) {
        res = min(res, *r - *l + 1 + f(d+1, y + i));
    }
    i = 0;
    l = t[d].begin();
    while (++i, (--r) != t[d].begin()) {
        res = min(res, *r - *l + 1 + f(d+1, y + i));
    }
    return dp[d][y] = res;
}

int main(void) {
    memset(dp, -1, sizeof dp);
    cin >> n >> m >> k;
    REP(i, n) {
        REP(j, m) {
            cin >> c;
            if (c == '1') t[i].pb(j);
        }
    }
    cout << f(0, 0) << endl;
    return 0;
}
