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

ll l, r;

int main(void) {
    ios_base::sync_with_stdio(0), cin.tie(nullptr);
    // freopen("input.txt", "r", stdin);
    cin >> l >> r;
    for (ll a = l; a + 2 <= r; ++a) {
        for (ll c = a+2; c <= r; ++c) if (__gcd(a, c) != 1) {
            for (ll b = a+1; b < c; ++b) {
                if (__gcd(a, b) == 1 && __gcd(b, c) == 1)
                    return cout << a << ' ' << b << ' ' << c << endl, 0;
            }
        }
    }
    cout << -1 << endl;
    return 0;
}
