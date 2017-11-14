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

const int INF = (int)1e9 + 7;
const long long LLINF = (ll)4e18 + 7;
const double pi = acos(-1.0);

#define deb(x) cerr << #x << " = " << x << endl
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

const int N = 1e2+7;
int n, m;
bool flag, done[N];
vector<int> v, e[N], groups[N];
deque<int> q;

void dfs(int p) {
    done[p] = 1;
    v.pb(p);
    for (auto u : e[p]) {
        if (!done[u]) dfs(u);
    }
}

int main(void) {
    ios_base::sync_with_stdio(0), cin.tie(nullptr);
    cin >> n >> m;
    REP(i, m) {
        int a, b; cin >> a >> b;
        e[a].pb(b);
        e[b].pb(a);
    }

    int k = 0;
    FOR(i, 1, n+1)  if (!done[i]) {
        v.clear();
        dfs(i);
        if (sz(v) > 3) {
            flag = 1;
            break;
        }
        if (sz(v) == 1) q.pb(v[0]);
        else groups[k++] = v;
    }

    if (!flag) REP(i, n/3) {
        auto& g = groups[i];
        while (sz(g) != 3) {
            if (q.empty()) {
                flag = 1;
                break;
            }
            g.pb(q.front());
            q.pop_front();
        }
        sort(all(g), greater<int>());
    }

    if (flag) return cout << -1 << endl, 0;
    REP(i, n/3) {
        auto g = groups[i];
        cout << g[0] << ' ' << g[1] << ' ' << g[2] << endl;
    }
    return 0;
}
