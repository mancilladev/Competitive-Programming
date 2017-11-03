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

const int N = 1e5+7;
ll x, y, n, nxt;

ll MOD(ll n) {
    ll r = n%INF;
    return (r < 0 ? r+INF : r);
}

int main(void) {
    ios_base::sync_with_stdio(0), cin.tie(nullptr);
    cin >> x >> y >> n;
    if (n < 3) return cout << (n == 2 ? MOD(y) : MOD(x)) << endl, 0;
    vector<int> sol;
    FOR(i, 3, 9) {
        nxt = MOD(y - x);
        x = y;
        y = nxt;
        sol.pb(y);
    }
    cout << sol[(n-3)%sz(sol)] << endl;
    return 0;
}
