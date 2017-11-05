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
int n, m, pos, t;
string stump = "_o_";
string trunk = "/|\\";
string base = "_|_";

void draw(vector<vector<char>>& C) {
    REP(i,m+2) cout << '*'; cout << endl;
    FORD(i, m-1, 0) {
        cout << '*';
        REP(j, m) cout << C[i][j];
        cout << '*';
        cout << endl;
    }
    REP(i,m+2) cout << '*'; cout << endl;
    cout << endl;
}

int main(void) {
    ios_base::sync_with_stdio(0), cin.tie(nullptr);
    while (cin >> m >> n) {
        vector<vector<char>> C(m, vector<char>(m, '.'));
        REP(_, n) {
            int s, x, y; cin >> s >> x >> y;
            if (x+1 < 0 || x-1 >= m || y+s+2 < 0 || y > m) {
                continue;
            }

            // stump
            if (s == 0) {
                pos = 0;
                FOR(i, x-1, x+2) {
                    if (i >= 0 && i < m) C[y][i] = stump[pos];
                    ++pos;
                }
            } else {
                // base of the tree
                pos = 0;
                if (y >= 0 && y < m) FOR(i, x-1, x+2) {
                    if (i >= 0 && i < m) C[y][i] = base[pos];
                    ++pos;
                }
                // trunk
                FOR(j, y+1, y+1+s) {
                    pos = 0;
                    if (j >= 0 && j < m) FOR(i, x-1, x+2) {
                        if (i >= 0 && i < m) C[j][i] = trunk[pos];
                        ++pos;
                    }
                }
                // top
                int t = y+1+s;
                if (t >= 0 && t < m && x >= 0 && x < m)
                    C[t][x] = '^';
            }
        }
        draw(C);
    }
    return 0;
}
