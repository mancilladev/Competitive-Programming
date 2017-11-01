#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
template <class T> using min_queue = priority_queue<T, vector<T>, greater<T>>;
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int INF = static_cast<int>(1e9);
const long long LLINF = static_cast<long long>(4e18);
const double pi = acos(-1.0);

#define error(x) cerr << #x << " = " << x << endl
#define sz(a) static_cast<int>((a).size())
#define all(a) (a).begin(), (a).end()
#define sq(x) (x) * (x)
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define endl '\n'

#define UNIQUE(a) sort(all(a)), (a).erase(unique(all(a)), (a).end())
#define FOR(i, a, b) for (int i(a), b_(b); i < b_; ++i)
#define REP(i, n) FOR (i, 0, n)
#define FORD(i, a, b) for (int i(a), b_(b); i >= b_; --i)

const int N = 1e5+7;
int n, m;

vector<int> g[N], used(N), e(2);
vector<pii> del;

void dfs(int p) {
    if (used[p]) return;
    used[p] = 1;
    for (auto u : g[p]) {
        if (used[u]) del.eb(p, u);
        dfs(u);
    }
}

int main(void) {
    ios_base::sync_with_stdio(0), cin.tie(nullptr);
    cin >> n >> m;
    REP(i, m) {
        int x, y; cin >> x >> y;
        --x; --y;
        g[x].pb(y);
        g[y].pb(x);
    }
    if (m < n-1) return cout << -1 << endl, 0;
    REP(i, n) {
        if (!used[i]) dfs(i);
    }
    cout << sz(del) << endl;
    REP(i, sz(del)) {
        cout << del[i].f << ' ' << del[i].s << ' ' << del[i].s << ' ' << del[(i+1)%sz(del)].s << endl;
    }
    return 0;
}
