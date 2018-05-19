#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#ifdef LOCAL
#define deb(x) cout << #x << " = " << x << endl
#else
#define deb(x) 0
#endif
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()
#define sq(x) (x) * (x)
#define fi first
#define se second
#define FOR(i, a, b) for (int i(a); i < b; ++i)
#define REP(i, n) FOR (i, 0, n)
#define FORD(i, a, b) for (int i(a); i >= b; --i)

const int MN = 2e5 + 7;
int N, M, S, A, B;

int main (void) {
    while (cin >> N >> M >> S >> A >> B) {
        vector<int> adj[N+7];
        REP(i, M) {
            int a, b; cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        function<vector<int>(int)> bfs = [&](int s) {
            queue<int> q;
            vector<int> d(N+7, -1);
            q.push(s);
            d[s] = 0;
            while (!q.empty()) {
                int v = q.front();
                q.pop();
                for (auto to : adj[v]) {
                    if (d[to] != -1) continue;
                    q.push(to);
                    d[to] = d[v] + 1;
                }
            }
            return d;
        };
        vector<int> dS, dA, dB;
        dS = bfs(S);
        dA = bfs(A);
        dB = bfs(B);
        int ans = 0;
        FOR(i, 1, N+1) {
            if ((dS[A] == dS[i] + dA[i]) && (dS[B] == dS[i] + dB[i])) {
                ans = max(ans, dS[i]);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
