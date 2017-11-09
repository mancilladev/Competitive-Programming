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
int n, m, a[N], d[N], cnt[N];
bool done[N];

bool check(int x) {
    memset(done, 0, sizeof done);
    memset(cnt, 0, sizeof cnt);
    vector<int> v;
    int cur = 0;
    FORD(i, x, 1) {
        if (d[i] != 0 && !done[d[i]]) {
            done[d[i]] = true;
            cnt[d[i]] = a[d[i]];
            v.pb(d[i]);
        } else {
            if (cur < sz(v)) {
                cnt[v[cur]]--;
                if (cnt[v[cur]] == 0) ++cur;
            }
        }
    }
    FOR(i, 1, m+1) if (!done[i]) return 0;
    return cur == sz(v);
}

int main(void) {
    ios_base::sync_with_stdio(0), cin.tie(nullptr);
    cin >> n >> m;
    FOR(i, 1, n+1) cin >> d[i];
    FOR(i, 1, m+1) cin >> a[i];

    int day = 0;
    for (int k = n; k >= 1; k /= 2) {
        while (day + k <= n && !check(day + k)) day += k;
    }
    ++day;

    cout << (day > n ? -1 : day) << endl;
    return 0;
}
