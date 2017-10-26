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
int n;

int main(void) {
    ios_base::sync_with_stdio(0), cin.tie(nullptr);
    cin >> n;
    int cur = 0;
    for (int i = 0; i < n; ++i) {
        int s, d; cin >> s >> d;
        int x = 0;
        while (s + x * d <= cur) ++x;
        cur = s + ceil(x) * d;
    }
    cout << cur << endl;
    return 0;
}
