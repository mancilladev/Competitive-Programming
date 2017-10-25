#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef pair<int,int> pii;
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define error(x) cerr << #x << " = " << x << endl
#define sz(x) (int)(x).size()
#define eb emplace_back
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

const int INF = 1e9 + 7;

int f(int x, int y) {
    if (max(x, y) <= 1) return 0;
    for (int i = 1; 2 * i <= x; ++i)
        if (f(x-2*i, y+i) == 0) return 1;
    for (int i = 1; 2 * i <= y; ++i)
        if (f(x+i, y-2*i) == 0) return 1;
    return 0;
}

int main(void) {
    ios_base::sync_with_stdio(0), cin.tie(nullptr);
    ll x, y; cin >> x >> y;
    if (llabs(x - y) > 1) cout << "Alice\n";
    else cout << "Brown\n";
    return 0;
}
