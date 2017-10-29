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
int n, arr[100005];

ll f() {
    ll res = 0;
    ll sum = 0;
    for (int i = 0; i < n; ++i) {
        if (i&1) {
            if (sum + arr[i] >= 0) {
                res += llabs(sum + arr[i] - (-1));
                sum = -1;
            } else {
                sum += arr[i];
            }
        } else {
            if (sum + arr[i] <= 0) {
                res += llabs(sum + arr[i] - 1);
                sum = 1;
            } else {
                sum += arr[i];
            }
        }
    }
    return res;
}

int main(void) {
    ios_base::sync_with_stdio(0), cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> arr[i];
    ll res = f();
    for (int i = 0; i < n; ++i) arr[i] *= -1;
    res = min(res,f());
    cout << res << '\n';
    return 0;
}
