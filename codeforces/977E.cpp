#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = (int)1e9 + 7;
#define deb(x) cerr << #x << " = " << x << endl
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()
#define sq(x) (x) * (x)
#define fi first
#define se second
#define UNIQUE(a) sort(all(a)), (a).erase(unique(all(a)), (a).end())
#define FOR(i, a, b) for (int i(a); i < b; ++i)
#define REP(i, n) FOR (i, 0, n)
#define FORD(i, a, b) for (int i(a); i >= b; --i)

const int MN = 2e5 + 7;
int N, M, deg[MN];
bool used[MN];

struct DSU {
    vector<int> parent;
    vector<vector<int>> lst;
    void init(int n) {
        parent.resize(n);
        lst.resize(n);
        REP(i, n)
            make_set(i);
    }
    void make_set(int v) {
        parent[v] = v;
        lst[v] = vector<int>(1, v);
    }
    int find_set(int v) {
        return parent[v];
    }
    void union_sets(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a != b) {
            if (sz(lst[a]) < sz(lst[b]))
                swap(a, b);
            while (!lst[b].empty()) {
                int v = lst[b].back();
                lst[b].pop_back();
                parent[v] = a;
                lst[a].push_back(v);
            }
        }
    }
};

int main (void) {
    cin >> N >> M;
    DSU dsu = DSU();
    dsu.init(N);
    REP(i, M) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        ++deg[a];
        ++deg[b];
        dsu.union_sets(a, b);
    }
    int ans = 0;
    REP(i, N) {
        int v = dsu.find_set(i);
        if (used[v]) {
            continue;
        }
        used[v] = true;
        bool ok = true;
        for (auto u : dsu.lst[v]) ok &= (deg[u] == 2);
        if (ok) ++ans;
    }
    cout << ans << '\n';
    return 0;
}
