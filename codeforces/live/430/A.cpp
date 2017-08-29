#include <bits/stdc++.h>
#define PB push_back
using namespace std;
typedef long long ll;
typedef long double ld;
const ll INF = ll(1e18);

int l, r, x, y;
double k;
int main(void) {
    // freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(nullptr);
    cin >> l >> r >> x >> y >> k;
    for (int b = x; b <= y; ++b) {
        ll a = b * k;
        if (l <= a && a <= r && a/k == b)
            return cout << "YES" << endl, 0;
    }
    cout << "NO" << endl;

    return 0;
}
