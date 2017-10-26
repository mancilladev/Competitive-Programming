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
    cin >> n >> k;
    vector<int> a(n);
    for (auto& it : a) cin >> it;
    multiset<int> s;
    for (int i = 0; i < k && i < n; ++i) s.insert(a[i]);
    for (int i = 0; i < n; ++i) {
        if (i + k < n) s.insert(a[i+k]);
        int x = *(s.begin());
        if (x < a[i]) {
            for (int j = i + k; j >= i + 1; --j) {
                if (j < n && a[j] == x) {
                    swap(a[i], a[j]);
                    break;
                }
            }
            break;
        }
        s.erase(s.find(a[i]));
    }
    for (auto it : a) cout << it << ' ';
    cout << endl;
    return 0;
}
