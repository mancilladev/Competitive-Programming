#ifdef JUDGE
#include <fstream>
std::ifstream cin("input.txt");
std::ofstream cout("output.txt");
#else
#include <iostream>
#endif
#include <set>
#include <vector>
#include <unordered_map>
using namespace std;
unordered_map<int, set<int> > graph;
vector<int> color;

bool dfsK2(int v, int c = 1) {
    color[v] = c;
    int nextc = (c==1) ? 2 : 1;
    for (int u: graph[v]) {
        if (color[u] == 0)
            return dfsK2(u, nextc);
        return (color[u] != color[v]);
    }
    return true;
}

bool isBipartite() {
    for (auto &ve: graph) {
        if (color[ve.first] == 0 && dfsK2(ve.first) == false)
            return false;
    }
    return true;
}

int main() {
    int V, E; cin >> V >> E;
    color.resize(V+1, 0);

    for (int i = 0; i < E; ++i) {
        int k, v; cin >> k >> v;
        if (graph.find(k) != graph.end())
            graph[k].insert(v);
        else
            graph[k] = {v};
    }

    if (isBipartite()) cout << "YES\n";
    else cout << "NO\n";

    return 0;
}
