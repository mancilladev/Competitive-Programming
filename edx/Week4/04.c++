#ifdef JUDGE
#include <fstream>
std::ifstream cin("input.txt");
std::ofstream cout("output.txt");
#else
#include <iostream>
#endif
#include <vector>
#include <queue>
#include <set>
#include <unordered_map>
#define F first
#define S second
#define PB push_back
using namespace std;
const int INF(1e5);
vector<int> dist;
vector<bool> S;
int N, M;

unordered_map<short, unordered_map<short, int> > adj;

struct Vertex {
    short index;
    int w;
} vertex;

bool operator <(const Vertex& x, const Vertex& y) {
    return x.w > y.w;
}

void dijkstra() {
    priority_queue<Vertex> pq;
    pq.push({1, 0});

    while (!pq.empty()) {
        vertex = pq.top();
        pq.pop();
        short v = vertex.index;
        if (dist[v] != vertex.w)
            continue;

        S[v] = 1;
        for (auto kv: adj[v]) {
            short u = kv.F;
            int w = kv.S;
            dist[u] = min(dist[u], dist[v] + w);
            if (!S[u])
                pq.push({u, dist[u]});
        }
    }
}

int main() {
    cin >> N >> M;
    S.resize(N+1);
    dist.resize(N+1);

    dist[1] = 0;
    for (int i = 2; i <= N; ++i)
        dist[i] = INF, S[i] = 0;

    while (M--) {
        int a, b, c;
        cin >> a >> b >> c;
        if (adj[a].find(b) == adj[a].end())
            adj[a][b] = c;
        else
            adj[a][b] = min(adj[a][b], c);
        adj[b][a] = adj[a][b];
    }

    dijkstra();

    for (int i = 1; i <= N; ++i)
        cout << dist[i] << ' ';
    cout << endl;

    return 0;
}
