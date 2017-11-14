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
int n, m, bad;
bool used[N], done[N];
vector<int> e[N];

void dfs(int p) {
    if (done[p]) return;
    done[p] = 1;
    for (auto u : e[p]) dfs(u);
}

int main(void) {
    ios_base::sync_with_stdio(0), cin.tie(nullptr);
    cin >> n >> m;
    REP(i, n) {
        int k, y; cin >> k;
        if (!k) ++bad;
        else cin >> y, used[y] = 1;
        REP(j, k-1) {
            int x; cin >> x;
            used[x] = 1;
            e[y].pb(x);
            e[x].pb(y);
        }
    }
    int comps = 0;
    REP(i, m+1) if (used[i] && !done[i]) {
        ++comps;
        dfs(i);
    }
    cout << max(0, comps - 1) + bad << endl;
    return 0;
}
