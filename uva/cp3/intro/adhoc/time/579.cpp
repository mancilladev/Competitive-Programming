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

int main(void) {
    while (true) {
        double h, m;
        scanf("%lf:%lf", &h, &m);
        if (h == 0 && m == 0) break;
        double m_deg = m * (360 / 60);
        double h_deg = h * (360 / 12) + (m / 60) * (360 / 12);
        double res = abs(m_deg - h_deg);
        if (res > 180) res = 360 - res;
        printf("%.3lf\n", res);
    }
    return 0;
}
