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

const int MAX = 1007;
int T, A, H, B;
int x, y;
bool a[MAX][MAX];

int prob (int cx, int cy) {
    int p = 0;
    FOR(j, cy-1, cy+2) {
        FOR(i, cx-1, cx+2) {
            p += (a[j][i] == false);
        }
    }
    return p;
}

void interact (int cx, int cy) {
    cout << cx << ' ' << cy << endl;
    cin >> x >> y;
}

void print () {
    FOR(j, 1, H+1) {
        FOR(i, 1, B+1) {
            cerr << a[j][i];
        }
        cerr << '\n';
    }
}

void solve () {
    int cx = 2, cy = 2;

    while (true) {
        if (x == -1 && y == -1) deb(B), deb(H), print(), exit(-1);
        if (x == 0 && y == 0) return;

        a[y][x] = true;

        int cp = 0;
        FOR(j, 2, H) {
            FOR(i, 2, B) {
                int p = prob(i, j);
                if (p > cp) {
                    cp = p;
                    cy = j;
                    cx = i;
                }
            }
        }

        interact(cx, cy);
    }
}

int main (void) {
    cin >> T;
    FOR (tt, 1, T+1) {
        cin >> A;

        H = sqrt(A);
        B = A / H + (A%H > 0);
        x = MAX-1;
        y = MAX-1;

        memset(a, 0, sizeof a);
        solve();
    }

#ifdef LOCAL
    cerr << (double)clock()/CLOCKS_PER_SEC << endl;
#endif
    return 0;
}
