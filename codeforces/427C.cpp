#include <bits/stdc++.h>
#define fi first
#define se second
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()
#define deb(x) cout << #x << " = " << x << endl
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define fore(i, l, r) for (int i = (int)(l); i <= (int)(r); ++i)
#define ford(i, n) for (int i = (int)(n) -1; i >= 0; --i)

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

const int MN = 1e5 + 7, INF = 1e9 + 7;

struct Graph {
    int n;
    vector<vector<int>> adj;
    vector<int> cost;
    void init (int nn) {
        n = nn;
        adj.resize(n);
        cost.resize(n);
    }
    void setCost (int a, int val) {
        cost[a] = val;
    }
    void add (int a, int b) {
        adj[a].push_back(b);
    }
};

struct Tarjan {
    int numSCC, cur;
    vector<int> costSCC;
    vector<vector<int>> components;
    vector<int> pre, low, id;
    deque<int> st;
    Graph g;

    void init (Graph gg) {
        g = gg;
        cur = numSCC = 0;

        st.clear();
        id.resize(g.n);
        low.resize(g.n);
        pre.resize(g.n);
        fill(all(pre), -1);

        forn(i, g.n) {
            if (pre[i] == -1)
                dfs(i);
        }
    }

    void dfs (int a) {
        low[a] = pre[a] = cur++;
        st.push_back(a);

        for (auto to : g.adj[a]) {
            if (pre[to] == -1) dfs(to);
            low[a] = min(low[a], low[to]);
        }

        if (pre[a] == low[a]) {
            int minVal = INF;
            vector<int> v;
            while (true) {
                int b = st.back();
                st.pop_back();

                v.push_back(b);
                id[b] = numSCC;
                low[b] = g.n + 1;
                minVal = min(minVal, g.cost[b]);

                if (a == b)
                    break;
            }

            components.push_back(v);
            costSCC.push_back(minVal);
            ++numSCC;
        }
    }
};

int main (void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n, m;
    while (cin >> n) {
        Graph g = Graph();
        g.init(n);
        forn(i, n) {
            int c; cin >> c;
            g.setCost(i, c);
        }
        cin >> m;
        forn(i, m) {
            int a, b; cin >> a >> b;
            g.add(--a, --b);
        }

        Tarjan scc = Tarjan();
        scc.init(g);

        ll formas = 1, costo = 0;
        forn(i, scc.numSCC) {
            ll ways = 0;
            for (auto j : scc.components[i])
                if (g.cost[j] == scc.costSCC[i])
                    ++ways;
            formas *= ways;
            formas %= INF;
            costo += scc.costSCC[i];
        }
        cout << costo << ' ' << formas << '\n';
    }
    return 0;
}
