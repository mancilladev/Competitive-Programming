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

const int INF = static_cast<int>(1e9);
const long long LLINF = static_cast<long long>(4e18);
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

const int N = 1e5+7;
string s, a, b;
int n;

int in(string& c, int x) {
    REP(j, n) if (s[x+j] != c[j]) return 0;
    return 1;
}

int main(void) {
    ios_base::sync_with_stdio(0), cin.tie(nullptr);
    cin >> s >> a >> b;
    n = sz(a);
    int i = 0;
    while(i < sz(s)-sz(a)+1) {
        if (in(a, i)) {
            REP(j, n) s[i+j] = b[j];
            i += n;
            continue;
        }
        if (in(b, i)) {
            REP(j, n) s[i+j] = a[j];
            i += n;
            continue;
        }
        ++i;
    }
    cout << s << endl;
    return 0;
}
