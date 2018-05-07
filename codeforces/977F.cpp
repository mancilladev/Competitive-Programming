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
int N, a[MN];

int main (void) {
    ios_base::sync_with_stdio(0), cin.tie(nullptr);

    while (cin >> N) {
        map<int, int> dp;
        FOR(i, 1, N+1) {
            cin >> a[i];
        }

        int ans = 0;
        int lst = 0;
        FOR(i, 1, N+1) {
            int x = a[i];
            dp[x] = dp[x - 1] + 1;
            if (ans < dp[x]) {
                ans = dp[x];
                lst = x;
            }
        }

        deque<int> res;
        FORD(i, N, 1) {
            if (a[i] == lst) {
                res.push_front(i);
                --lst;
            }
        }

        cout << ans << '\n';
        for (auto it : res)
            cout << it << ' ';
        cout << '\n';
    }

    return 0;
}
