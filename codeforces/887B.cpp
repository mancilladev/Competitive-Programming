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
vector<unordered_set<int>> a(3);

int check(int x) {
    int k = log10(x) + 1;
    if (n < k) return 0;

    if (k == 1) {
        REP(i, n) if (a[i].find(x) != a[i].end()) return 1;
    }
    if (k == 2) {
        REP(i, n) {
            REP(j, n) {
                if (i != j &&
                    a[i].find(x/10) != a[i].end() &&
                    a[j].find(x%10) != a[j].end()) return 1;
            }
        }
    }
    if (k == 3) {
        REP(i, n) {
            REP(j, n) {
                REP(h, n) {
                    if (i != j && i != h && j != h &&
                        a[h].find(x/100) != a[h].end() &&
                        a[i].find(x/10) != a[i].end() &&
                        a[j].find(x%10) != a[j].end()) return 1;
                }
            }
        }
    }
    return 0;
}

int main(void) {
    ios_base::sync_with_stdio(0), cin.tie(nullptr);
    cin >> n;
    REP(i, n) {
        REP(j, 6) {
            int x; cin >> x;
            a[i].insert(x);
        }
    }
    FOR(i, 1, 1000) {
        if (!check(i)) return cout << i-1 << endl, 0;
    }
    return 0;
}
