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
int n;

bool valid(int x, int y) {
    while (x && y) {
        if (x%10 && y%10) return 0;
        x /= 10;
        y /= 10;
    }
    return 1;
}

int main(void) {
    ios_base::sync_with_stdio(0), cin.tie(nullptr);
    cin >> n;
    vector<int> a(n);
    REP(i, n) { cin >> a[i]; }

    vector<int> v;
    if (find(all(a), 0) != a.end()) v.pb(0);
    if (find(all(a), 100) != a.end()) v.pb(100);
    bool flag = 0;
    FOR(i, 1, 10) if (find(all(a), i) != a.end()) {
        v.pb(i);
        flag = 1;
        break;
    }
    FOR(i, 1, 10) if (find(all(a), i*10) != a.end()) {
        v.pb(i*10);
        flag = 1;
        break;
    }
    if (!flag) FOR(i, 1, 100) if (find(all(a), i) != a.end()) {
        v.pb(i);
        break;
    }

    cout << sz(v) << endl;
    REP(i, sz(v)) cout << v[i] << ' ';
    cout << endl;
    return 0;
}
