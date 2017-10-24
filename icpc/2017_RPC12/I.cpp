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

const int MOD = 1e9 + 7;

int orientation(pii p, pii q, pii r) {
    ll x = (ll)(r.f - p.f) * (ll)(r.f - q.f) > 0;
    ll y = (ll)(r.s - p.s) * (ll)(r.s - q.s) > 0;
    return x != y;
}

int intersects(pii p1, pii q1, pii p2, pii q2) {
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);
    return (o1 != o2 && o3 != o4);
}

int T;
int main(void) {
    ios_base::sync_with_stdio(0), cin.tie(nullptr);
    cin >> T;
    for (int tt = 0; tt < T; ++tt) {
        int n; cin >> n;
        vector<pair<pii,pii>> lines;
        for (int i = 0; i < n; ++i) {
            int a, b, c, d; cin >> a >> b >> c >> d;
            lines.pb({{a,b}, {c,d}});
        }
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i+1; j < n; ++j)
                if (intersects(lines[i].f, lines[i].s, lines[j].f, lines[j].s))
                    ++cnt;
        }
        if (tt) cout << '\n';
        cout << 2 * cnt + n << '\n';
    }
    return 0;
}
