#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef long double ld;
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
int pos = 0;
ld cnt = 0;

void solve(int x, int p) {
    if (x == 0) {
        cnt += (p == pos);
        return;
    }
    --x;
    solve(x, p + 1);
    solve(x, p - 1);
}

int main(void) {
    // freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(nullptr);
    string s1, s2; cin >> s1 >> s2;
    for (auto c : s1) pos += (c == '+' ? 1 : -1);
    int prev = 0;
    int unknown = 0;
    for (auto c : s2) {
        if (c == '?') ++unknown;
        else prev += (c == '+' ? 1 : -1);
    }
    solve(unknown, prev);
    cout << setprecision(12) << (cnt / pow(2, unknown)) << endl;
    return 0;
}
