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
#ifdef LOCAL
inline void OPEN (string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}
#endif

const int INF = (int)1e9 + 7;
const long long LLINF = (ll)4e18 + 7;
const double pi = acos(-1.0);

#define deb(x) cerr << #x << " = " << x << endl
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()
#define sq(x) (x) * (x)
#define fi first
#define se second
#define endl '\n'

#define UNIQUE(a) sort(all(a)), (a).erase(unique(all(a)), (a).end())
#define FOR(i, a, b) for (int i(a); i < b; ++i)
#define REP(i, n) FOR (i, 0, n)
#define FORD(i, a, b) for (int i(a); i >= b; --i)

ll T, N, M;
const int LIM = 1e5 + 7;
int a[LIM];

void troubleSort () {
    bool done = false;
    while (!done) {
        done = true;
        REP(i, N - 2) {
            if (a[i] > a[i+2]) {
                done = false;
                swap(a[i], a[i+2]);
            }
        }
    }
}

int isSorted () {
    REP(i, N-1) {
        if (a[i] > a[i+1])
            return i;
    }
    return -1;
}

int solve () {
    troubleSort();
    return isSorted();
}

int main (void) {
    ios_base::sync_with_stdio(0), cin.tie(nullptr);
#ifdef LOCAL
    OPEN("p2");
#endif

    cin >> T;
    FOR (tt, 1, T+1) {
        cin >> N;
        REP(i, N) cin >> a[i];

        cout << "Case #" << tt << ": ";
        int ans = solve();
        if (ans == -1) cout << "OK\n";
        else cout << ans << '\n';
    }

#ifdef LOCAL
    cerr << (double)clock()/CLOCKS_PER_SEC << endl;
#endif
    return 0;
}
