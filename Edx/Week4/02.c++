#ifdef JUDGE
#include <fstream>
std::ifstream cin("input.txt");
std::ofstream cout("output.txt");
#else
#include <iostream>
#endif
#include <set>
#include <deque>
#include <vector>
#include <unordered_map>
using namespace std;
unordered_map<int, set<int> > graph;
vector<int> color;

bool bfsK2(int src) {
    if (color[src] != -1) return true;

    color[src] = 1;
    deque<int> q;
    q.push_back(src);

    while (!q.empty()) {
        int v = q.front(); q.pop_front();
        for (int u: graph[v]) {
            if (color[u] == -1) {
                color[u] = 1 - color[v];
                q.push_back(u);
            }
            else if (color[u] == color[v])
                return false;
        }
    }

    return true;
}

bool isBipartite() {
    for (auto &kv: graph) if (bfsK2(kv.first) == false)
        return false;
    return true;
}

int main() {
    int V, E; cin >> V >> E;
    color.resize(V+1, -1);

    for (int i = 0; i < E; ++i) {
        int u, v; cin >> u >> v;
        if (graph.find(u) != graph.end())
            graph[u].insert(v);
        else
            graph[u] = {v};

        if (graph.find(v) != graph.end())
            graph[v].insert(u);
        else
            graph[v] = {u};
    }

    if (isBipartite()) cout << "YES\n";
    else cout << "NO\n";

    return 0;
}
