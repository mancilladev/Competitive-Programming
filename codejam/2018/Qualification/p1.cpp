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

ll T, N, M, D;
string S;

ll bestCase () {
    ll p = 1, x = 0;
    for (char c : S) if (c == 'S') x += p;
    for (char c : S) if (c == 'C') p <<= 1;
    return x;
}

ll power () {
    ll p = 1, x = 0;
    for (char c : S) {
        if (c == 'C') p <<= 1;
        else x += p;
    }
    return x;
}

void ordenar () {
    FORD(i, sz(S)-2, 0) {
        if (S[i] == 'C' && S[i+1] != 'C') {
            swap(S[i], S[i+1]);
            return;
        }
    }
}

ll solve () {
    if (bestCase() > D)
        return -1;
    int res = 0;
    while (power() > D) {
        ++res;
        ordenar();
    }
    return res;
}

int main (void) {
    ios_base::sync_with_stdio(0), cin.tie(nullptr);
    OPEN("p1");

    cin >> T;
    FOR (tt, 1, T+1) {
        cin >> D >> S;

        cout << "Case #" << tt << ": ";
        ll ans = solve();
        if (ans == -1) cout << "IMPOSSIBLE\n";
        else cout << ans << '\n';
    }

#ifdef LOCAL
    cerr << (double)clock()/CLOCKS_PER_SEC << endl;
#endif
    return 0;
}
