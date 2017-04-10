#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_map>
#define F first
#define S second
#define PB push_back
typedef long long ll;
using namespace std;
vector<int> color;
unordered_map<int, int> graph;

int circleSize() {
    for (auto &kv: graph) {
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);

    int T; cin >> T;
    for (int t = 1; t <= T; ++t) {
        int N; cin >> N;
        color.clear();
        color.resize(N+1, 0);
        for (int k = 1; k <= N; ++k)
            cin >> v, graph[k] = v;

        cout << "Case #" << t << ": ";
        cout << circleSize();
        cout << '\n';
    }

    return 0;
}
