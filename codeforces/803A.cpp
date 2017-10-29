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
#define sq(x) (x) * (x)
#define eb emplace_back
#define pb push_back
#define f first
#define s second
#define endl '\n'

const int INF = 1e9 + 7;
int n, k;

int main(void) {
    ios_base::sync_with_stdio(0), cin.tie(nullptr);
#ifdef LOCAL
    //freopen("input.txt", "r", stdin);
#endif

    cin >> n >> k;
    vector<vector<int>> M(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int sum = (M[i][j]^1) + (M[i][j]^1);
            if (i == j && sum) --sum;
            if (sum > 0 && sum <= k) {
                M[i][j] = M[j][i] = 1;
                k -= sum;
            }
        }
    }
    if (k > 0) cout << -1 << endl;
    else {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (j > 0) cout << ' ';
                cout << M[i][j];
            }
            cout << endl;
        }
    }

#ifdef LOCAL
    cout << endl << endl << static_cast<double>(clock()) / CLOCKS_PER_SEC << endl;
#endif
    return 0;
}
