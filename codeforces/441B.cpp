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
int n, v;
ll res;

int main(void) {
    ios_base::sync_with_stdio(0), cin.tie(nullptr);
    cin >> n >> v;
    vector<pii> a(n);
    REP(i, n) {
        cin >> a[i].f >> a[i].s;
    }
    REP(day, 3001) {
        int cur = 0;
        for (auto& p : a) {
            if (p.f == day || p.f+1 == day) {
                int collect = min(p.s, v-cur);
                cur += collect;
                p.s -= collect;
            }
            if (cur == v) break;
        }
        res += cur;
    }
    cout << res << endl;
    return 0;
}
