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

const int N = 1e5 + 7, MOD = 1e9 + 7, MAX = 1e7 + 7;
int n, dp[MAX][4];

// memoization
int f(int k, int cur) {
    if (k == n) return cur == 0;
    if (dp[k][cur] != -1) return dp[k][cur];

    int res = 0;
    REP(i, 4) {
        if (i == cur) continue;
        res += f(k+1, i);
        res %= MOD;
    }
    return dp[k][cur] = res;
}

int main(void) {
    cin >> n;
    // base case
    dp[n][0] = 1;
    FORD(k, n-1, 0) {
        REP(cur, 4) {
            REP(i, 4) {
                if (cur == i) continue;
                dp[k][cur] += dp[k+1][i];
                dp[k][cur] %= MOD;
            }
        }
    }
    cout << dp[0][0] << endl;
    return 0;
}
