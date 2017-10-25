#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef pair<int,int> pii;
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
inline void OPEN (string s) {
    #ifdef DLOCAL
    freopen ((s + ".in").c_str (), "r", stdin);
    freopen ((s + ".out").c_str (), "w", stdout);
    #endif
}

#define error(x) cerr << #x << " = " << x << endl
#define sz(x) (int)(x).size()
#define sq(x) (x) * (x)
#define eb emplace_back
#define pb push_back
#define f first
#define s second
#define endl '\n'

const int MOD = 1e9 + 7;
const ll INF = ll(1e18);
ll T, N, M;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(nullptr);
    cin >> T;
    for (int t = 1; t <= T; ++t) {

        cout << "Case #" << t << ": ";
        cout << '\n';
    }
    return 0;
}
