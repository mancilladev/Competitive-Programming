#include <bits/stdc++.h>
using namespace std;
#define PB push_back
typedef long double ld;
const ld INF = ld(1e18);

int n;
vector<int> g[100007];

ld dfs(int v = 0, int p = -1) {
    ld sum = 0;
    for(int u : g[v])
        if (u != p)
            sum += dfs(u, v) + 1;
    return sum ? sum / (g[v].size() - (p != -1)) : 0;
}

int main(void) {
    ios_base::sync_with_stdio(0), cin.tie(nullptr);
    cin >> n;
    for (int a, b, i = 1; i < n; ++i) {
        cin >> a >> b, a--, b--;
        g[a].PB(b);
        g[b].PB(a);
    }
    cout << fixed << setprecision(7) << dfs() << endl;
    return 0;
}
