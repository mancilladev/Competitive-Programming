#ifdef JUDGE
#include <fstream>
std::ifstream cin("input.txt");
std::ofstream cout("output.txt");
#else
#include <iostream>
#endif
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;
typedef long long ll;
const ll INF = ll(1e18);
ll N, M, S, a, b, c, dist[2007];
bool neg[2007], in_g[2007];
unordered_map<ll, unordered_set<ll> > graph;

struct Edge {
    ll u;
    ll v;
    ll w;
} e;

vector<Edge> edges;

void reachable(ll u) {
    in_g[u] = 1;
    for (ll v: graph[u])
        if (!in_g[v]) reachable(v);
}

void setNegative(ll u) {
    neg[u] = 1;
    for (ll v: graph[u])
        if (in_g[v] && !neg[v]) setNegative(v);
}

void bellmanFord() {
    for (int i = 0; i < N - 1; ++i) {
        for (Edge e: edges) {
            if (in_g[e.u])
                dist[e.v] = min(dist[e.v], dist[e.u] + e.w);
        }
    }

    for (Edge e: edges) {
        if (!in_g[e.u]) continue;
        ll cur = min(dist[e.v], dist[e.u] + e.w);
        if (cur < dist[e.v])
            setNegative(e.v); // DFS from this node
        dist[e.v] = cur;
    }
}

int main() {
    cin >> N >> M >> S;

    for (int i = 1; i <= N; ++i)
        dist[i] = INF, neg[i] = in_g[i] = 0;
    dist[S] = 0;

    while (M--) {
        cin >> a >> b >> c;
        graph[a].insert(b);
        e = {a, b, c};
        edges.push_back(e);
    }

    // DFS to find reachable points from S
    reachable(S);
    // Update distances
    bellmanFord();

    for (int i = 1; i <= N; ++i) {
        if (!in_g[i])
            cout << '*';
        else if (neg[i] == 1)
            cout << '-';
        else
            cout << dist[i];

        cout << '\n';
    }

    return 0;
}
