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

pii roundness(ll x) {
    int a = 0, b = 0;
    while (x%2 == 0) x /= 2, ++a;
    while (x%5 == 0) x /= 5, ++b;
    pii p {a, b};
    return p;
}

int main(void) {
    ios_base::sync_with_stdio(0), cin.tie(nullptr);
    cin >> n >> k;
    vector<pii> arr;
    for (int i = 0; i < n; ++i) {
        ll x; cin >> x;
        arr.pb(roundness(x));
    }
    return 0;
}
