#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef pair<int,int> pii;
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define error(x) cerr << #x << " = " << x << endl
#define sz(x) (int)(x).size()
#define sq(x) (x) * (x)
#define eb emplace_back
#define pb push_back
#define f first
#define s second
#define endl '\n'

const int INF = 1e9 + 7, MAX = 1e5 + 7;
int n, size, p[MAX], done[MAX] = {0};
vector<int> components;

void dfs(int u) {
    if (done[u]) return;
    done[u] = 1;
    ++size;
    dfs(p[u]);
}

int main(void) {
    ios_base::sync_with_stdio(0), cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> p[i];
    for (int i = 1; i <= n; ++i) if (!done[i]) {
        size = 0;
        dfs(i);
        components.pb(size);
    }
    sort(components.begin(), components.end());
    if (sz(components) > 1) {
        int t = components[sz(components)-2] + components[sz(components)-1];
        components.pop_back(); components.pop_back();
        components.pb(t);
    }
    ll res = 0;
    for (auto x : components) res += sq((ll)x);
    cout << res << endl;
    return 0;
}
