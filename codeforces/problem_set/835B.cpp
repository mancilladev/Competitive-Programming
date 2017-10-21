#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

#define error(x) cerr << #x << " = " << x << endl
#define sz(x) (int)(x).size()
#define eb emplace_back
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

const int MOD = 1e9 + 7;

int main(void) {
    // freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(nullptr);
    int s = 0, cnt[10] = {0};
    int k; cin >> k;
    char c;
    while (cin >> c) {
        s += c - '0';
        cnt[c - '0']++;
    }
    int res = 0, i = 0;
    while (s < k) {
        if (cnt[i] == 0) ++i;
        else s += (9 - i), --cnt[i], ++res;
    }
    cout << res << endl;
    return 0;
}
