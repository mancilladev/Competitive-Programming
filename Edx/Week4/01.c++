#ifdef JUDGE
#include <fstream>
std::ifstream cin("input.txt");
std::ofstream cout("output.txt");
#else
#include <iostream>
#endif
#include <algorithm>
#include <vector>
#include <map>
#include <set>
using namespace std;

int n, m, last;
map<int, set<int> > graph;
vector<int> stack, color;

bool dfs(auto v) {
    color[v] = 1;
    if (graph.count(v) > 0) {
        stack.push_back(v);
        for (auto &u: graph[v]) {
            if (color[u] == 0 && dfs(u))
                return true;
            if (color[u] == 1) {
                last = u;
                return true;
            }
        }
        stack.pop_back();
    }
    color[v] = 2;
    return false;
}

int main() {
    cin >> n >> m;
    color.resize(n+1, 0);
    for (int i = 0; i < m; ++i) {
        int key, val; cin >> key >> val;
        if (graph.count(key) == 0)
            graph[key] = {val};
        else
            graph[key].insert(val);
    }

    bool acyclic = true;

    for (auto &kv: graph) {
        stack.clear();
        if (color[kv.first] == 0 && dfs(kv.first)) {
            acyclic = false;

            cout << "YES\n";
            auto it = stack.begin();
            while (*it != last)
                ++it;
            while (it != stack.end())
                cout << *it << ' ', ++it;
            cout << '\n';

            break;
        }
    }
    
    if (acyclic) cout << "NO\n";

    return 0;
}
