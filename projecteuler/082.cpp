#include <bits/stdc++.h>
using namespace std;
freopen("file_082.txt", "r", stdin);
typedef long long ll;

const ll INF = 1e17;
const int N = 80;
vector<vector<int> > M(N, vector<int>(N));
unordered_map<int, vector<int>> adj;
unordered_map<int, ll> w;

void dfs(int vertex) {
    for (auto u : adj[vertex])
        w[vertex] = vertex + min(w[vertex], dfs(u));
}

void getGraph() {
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j) {
            cin >> M[i][j];
            w[M[i][j]] = INF;
        }
    // last row has distance to oneself of oneself
    for (int i = 0; i < N; ++i)
        w[M[i][N-1]] = M[i][N-1];
    // first and last rows edges
    for (int i = 1; i < N-1; ++i) {
        adj[M[0][i]].push_back(M[1][i]);
        adj[M[0][i]].push_back(M[0][i+1]);

        adj[M[N-1][i]].push_back(M[N-2][i]);
        adj[M[N-1][i]].push_back(M[N-1][i+1]);
    }
}

int main(int argc, char const *argv[]) {
    getGraph();

    ll res = INF;
    for (int i = 0; i < N; ++i) {
        dfs(M[i][1]);
        res = min(res, M[i][0] + w[M[i][1]]);
    }
    cout << res << endl;
    return 0;
}
