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

const int MN = 1e5 + 7;
int N, M;
vector<int> adj[MN];

int main (void) {
    while (cin >> N >> M) {
        vector<int> g(N), pos(N+1);
        REP(i, N) {
            cin >> g[i];
            pos[g[i]] = i;
        }
        REP(i, M) {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        function<bool(int,int)> cmp = [&](int a, int b) {
            return pos[a] < pos[b];
        };
        REP(i, N+1) sort(all(adj[i]), cmp);
        vector<int> used(N+1, 0);
        int nxt = 0;
        function<bool(int)> dfs = [&](int u) {
            if (g[nxt] != u) return false;
            ++nxt;
            used[u] = true;
            bool ok = true;
            for (auto to : adj[u]) {
                if (used[to]) continue;
                ok &= dfs(to);
            }
            return ok;
        };
        cout << dfs(g[0]) << '\n';
    }
    return 0;
}
