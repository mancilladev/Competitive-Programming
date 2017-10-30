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
#define f first
#define s second
#define endl '\n'

#define UNIQUE(a) sort(all(a)), (a).erase(unique(all(a)), (a).end())
#define FOR(i, a, b) for (int i(a), b_(b); i < b_; ++i)
#define REP(i, n) FOR (i, 0, n)
#define FORD(i, a, b) for (int i(a), b_(b); i >= b_; --i)

const int N = 2e5;
int n, m, a, b, c[N], used[N];
ll res;
vector<int> g[N];
vector<pii> v;

int main(void) {
    ios_base::sync_with_stdio(0), cin.tie(nullptr);
    cin >> n >> m;
    REP(i, n) {
        cin >> c[i+1];
        v.eb(c[i+1], i+1);
    }
    sort(all(v), greater<pii>());
    REP(i, m) {
        cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }
    REP(i, n) {
        int q = v[i].s;
        REP(j, sz(g[q])) {
            int t = g[q][j];
            if (used[t]) continue;
            res += c[t];
        }
        used[q] = 1;
    }
    cout << res << endl;
    return 0;
}
