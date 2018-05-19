#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = (int)1e9 + 7;
#define deb(x) cout << #x << " = " << x << endl
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

int main (void) {
    while (cin >> N >> M) {
        vector<int> adj[N+7];
        REP(i, M) {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        if (M < N-1) {
            cout << -1 << '\n';
            continue;
        }

        vector<pii> edges;
        vector<int> color(N+7, 0);
        function<void(int,int)> dfs = [&](int v, int p) {
            color[v] = 1;
            for (auto to : adj[v]) {
                if (to == p) continue;

                if (color[to] == 1) edges.emplace_back(to, v);
                else if (color[to] == 0)  dfs(to, v);
            }
            color[v] = 2;
        };

        vector<int> comp;
        FOR(i, 1, 1+N) {
            if (color[i] == 0) {
                comp.push_back(i);
                dfs(i, -1);
            }
        }

        cout << sz(comp) - 1 << '\n';
        REP(i, sz(comp)-1) {
            cout << edges[i].fi << ' ' << edges[i].se << ' ';
            cout << comp[i] << ' ' << comp[sz(comp)-1] << '\n';
        }
    }
    return 0;
}
