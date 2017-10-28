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
int n, a, b;
vector<pii> arr;

int t(pii p, pii q) {
    return p.f + q.f <= b && max(p.s, q.s) <= a;
}

int t2(pii p, pii q) {
    return p.s + q.s <= a && max(p.f, q.f) <= b;
}

int test(int x, int y) {
    int area = arr[x].f * arr[x].s + arr[y].f * arr[y].s;
    for (int i = 0; i < 2; ++i) {
        swap(arr[x].f, arr[x].s);
        for (int j = 0; j < 2; ++j) {
            swap(arr[y].f, arr[y].s);
            if (t(arr[x], arr[y]) || t2(arr[x], arr[y])) return area;
        }
    }
    return 0;
}

int main(void) {
    ios_base::sync_with_stdio(0), cin.tie(nullptr);
    cin >> n >> a >> b;
    for (int i = 0; i < n; ++i) {
        int x, y; cin >> x >> y;
        arr.eb(x, y);
    }
    int res = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            res = max(res, test(i, j));
        }
    }
    cout << res << endl;
    return 0;
}
