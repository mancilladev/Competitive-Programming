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

int n, m;
vector<pii> stu, che;

int dist(pii p, pii q) {
    return abs(p.f - q.f) + abs(p.s - q.s);
}

int main(void) {
    ios_base::sync_with_stdio(0), cin.tie(nullptr);
    cin >> n >> m;
    int x, y;
    for (int i = 0; i < n; ++i) {
        cin >> x >> y;
        stu.eb(x,y);
    }
    for (int i = 0; i < m; ++i) {
        cin >> x >> y;
        che.eb(x,y);
    }
    for (auto p : stu) {
        int res = 0;
        for (int i = 0; i < m; ++i) {
            if (dist(p, che[i]) < dist(p, che[res]))
                res = i;
        }
        cout << res+1 << '\n';
    }
    return 0;
}
