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
ll a, b, c;

ll S(ll n) {
    if (n < 0) return -1;
    ll sum = 0;
    while(n) {
        sum += n%10;
        n /= 10;
    }
    return sum;
}

ll poww(ll n, ll k) {
    ll res = 1;
    REP(i, k) res *= n;
    return res;
}

int main(void) {
    ios_base::sync_with_stdio(0), cin.tie(nullptr);
    cin >> a >> b >> c;
    vector<int> sol;
    FOR(sx, 1, 82) {
        ll x = b * poww(sx, a) + c;
        if (S(x) == sx && x < INF) {
            sol.pb(x);
        }
    }
    cout << sz(sol) << endl;
    for (auto x : sol) cout << x << ' ';
    cout << endl;
    return 0;
}
