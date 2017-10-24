#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define error(x) cerr << #x << " = " << x << endl
#define sz(x) (int)(x).size()
#define eb emplace_back
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

const int MOD = 1e9 + 7, MAX = 1e7 * 3;
int a, b;
vector<int> isp(MAX+1, 1);
int main(void) {
    ios_base::sync_with_stdio(0), cin.tie(nullptr);
    isp[0] = isp[1] = 0;
    for (ll i = 2; i < MAX; ++i) if (isp[i]) {
        for (ll j = i*i; j < MAX; j += i) isp[j] = 0;
    }
    while (cin >> a >> b) {
        if (a == 0 && b == 0) break;
        if (a > b) swap(a, b);
        int res = 0;
        int past = 0;
        for (int i = a; i <= b; ++i) if (isp[i]) {
            if (past == 0) past = i;
            res = max(res, i - past);
            past = i;
        }
        if (res) cout << res << '\n';
        else cout << "NULL\n";
    }
    return 0;
}
