#include <bits/stdc++.h>
using namespace std;
#define PB push_back
typedef long long ll;
typedef long double ld;
const ll INF = ll(1e18);
vector<int> depth(2001);
unordered_map<int, vector<int> > graph;
vector<int> roots;
int N, p;

int bfsDepth(int parent) {
    int depth = 0, increase = 1, next = 0;
    deque<int> dq;
    dq.PB(parent);
    while (!dq.empty()) {
        int v = dq.front();
        dq.pop_front();
        next += graph[v].size();
        if (--increase == 0) {
            ++depth;
            increase = next;
            next = 0;
        }
        for (int child: graph[v])
            dq.PB(child);
    }
    return depth;
}

int maxDepth() {
    int res = 0;
    for (int root: roots)
        res = max(res, bfsDepth(root));
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> N;
    int res = 0;
    for (int i = 1; i <= N; ++i) {
        cin >> p;
        if (p == -1)
            roots.PB(i);
        else
            graph[p].PB(i);
    }
    cout << maxDepth() << endl;

    return 0;
}
