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
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()
#define sq(x) (x) * (x)
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define fi first
#define se second

#define UNIQUE(a) sort(all(a)), (a).erase(unique(all(a)), (a).end())
#define FOR(i, a, b) for (int i(a); i < b; ++i)
#define REP(i, n) FOR (i, 0, n)
#define FORD(i, a, b) for (int i(a); i >= b; --i)

const int N = 1e5+7;
int T, a, b;
string answer;

bool bigger(int x) {
    cout << x << endl;
    cin >> answer;
    if (answer == "WRONG_ANSWER") exit(0);
    return answer == "TOO_BIG";
}

int main (void) {
    // ios_base::sync_with_stdio(0), cin.tie(nullptr);
    cin >> T;
    while (T--) {
        cin >> a >> b;
        int n; cin >> n;
        int guess = a;

        for (int k = (b - a)>>1; k >= 1; k >>= 1) {
            while (guess + k <= b && !bigger(guess + k) && answer != "CORRECT")
                guess += k;
            if (answer == "CORRECT")
                break;
            if (n-- == 0)
                exit(0);
        }
    }
    return 0;
}
