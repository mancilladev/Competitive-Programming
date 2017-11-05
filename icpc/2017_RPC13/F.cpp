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

const int N = 5e3+7;
int n, a[N], cache[N][N];

// memoization
int solve(int l, int r) {
    if (cache[l][r] != -1) return cache[l][r];
    if (l == r) return cache[l][r] = 0;

    if (a[l] == a[r]) return cache[l][r] = 1 + solve(l+1, r-1);
    return cache[l][r] = max(
        solve(l+1, r),
        solve(l, r-1)
    );
}

int main(void) {
    ios_base::sync_with_stdio(0), cin.tie(nullptr);
    while (cin >> n) {
        REP(i, n) cin >> a[i];

        // memset(cache, -1, sizeof cache);
        // cout << solve(0, n-1) << endl;

        // tabulation
        FOR(dist, 1, n) {
            REP(l, n-dist) {
                int r = l + dist;
                if (a[l] == a[r]) {
                    cache[l][r] = 1 + cache[l+1][r-1];
                } else {
                    cache[l][r] = max(cache[l+1][r], cache[l][r-1]);
                }
            }
        }
        cout << cache[0][n-1] << endl;
    }
    return 0;
}
