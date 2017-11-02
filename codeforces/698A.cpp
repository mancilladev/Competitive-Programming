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

#define error(x) cerr << #x << " = " << x << endl
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

const int N = 107;
int n, a[N], cache[N][3];

// 0-rest, 1-contest, 2-gym
int dp(int day, int last) {
    // base
    if (day == n) return 0;

    // save the day
    if (cache[day][last] != -1)
        return cache[day][last];

    // lazy day
    int res = 1 + dp(day+1, 0);
    // contest day
    if (last != 1 && (a[day] == 2 || a[day] == 3)) {
        res = min(res, dp(day+1, 1));
    }
    // gym day
    if (last != 2 && (a[day] == 1 || a[day] == 3)) {
        res = min(res, dp(day+1, 2));
    }
    return cache[day][last] = res;
}

int main(void) {
    ios_base::sync_with_stdio(0), cin.tie(nullptr);
    cin >> n;
    REP(i, n) {
        cin >> a[i];
    }
    memset(cache, -1, sizeof cache);
    cout << dp(0, 0) << endl;
    return 0;
}
