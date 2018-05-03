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
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()
#define sq(x) (x) * (x)
#define fi first
#define se second

#define UNIQUE(a) sort(all(a)), (a).erase(unique(all(a)), (a).end())
#define FOR(i, a, b) for (int i(a); i < b; ++i)
#define REP(i, n) FOR (i, 0, n)
#define FORD(i, a, b) for (int i(a); i >= b; --i)

const int Z = 1e5 + 7;
int n, x, k;
vector<pii> a;

ll solve () {
    ll best = 0;
    REP(i, n) {
        if (a[i].fi > x)
            break;
        ll suma = 0;
        int p = i;
        FOR(j, i, n) {
            if (a[j].fi >= x && abs(a[i].fi - x) * 2 + abs(a[j].fi - x) > k)
                break;
            suma += a[j].se;
            p = j;
        }
        deb(i);
        deb(p);
        deb(suma);
        best = max(best, suma);
    }
    return best;
}

int main (void) {
    // ios_base::sync_with_stdio(0), cin.tie(nullptr);
    cin >> n >> x >> k;
    a.resize(n);
    REP(i, n) cin >> a[i].fi >> a[i].se;
    cout << solve() << endl;
    return 0;
}
