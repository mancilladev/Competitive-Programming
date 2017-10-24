#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define error(x) cerr << #x << " = " << x << endl
#define sz(x) (int)(x).size()
#define eb emplace_back
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

const int MOD = 1e9 + 7;

vector<vector<int>> adj;
vector<int> visited;

void dfs(int p) {
    if (visited[p]) return;
    visited[p] = 1;
    for (auto u : adj[p])
        dfs(u);
}

int components() {
    visited.clear();
    visited.resize(sz(adj));
    int res = 0;
    for (int i = 0; i < sz(adj); ++i)
        if (!visited[i])
            dfs(i), ++res;
    return res;
}

int main(void) {
    ios_base::sync_with_stdio(0), cin.tie(nullptr);
    string s;
    while (getline(cin, s)) {
        if (sz(s) == 0) cout << components() << '\n';
        else if (sz(s) == 1) {
            adj.clear();
            adj.resize(s[0] - 'A' + 1);
        }
        else {
            int a = s[0] - 'A';
            int b = s[1] - 'A';
            adj[a].pb(b);
            adj[b].pb(a);
        }
    }
    cout << components() << '\n';
    return 0;
}
