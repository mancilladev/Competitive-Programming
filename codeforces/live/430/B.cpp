#include <bits/stdc++.h>
#define PB push_back
using namespace std;
typedef long long ll;
typedef long double ld;
const ll INF = ll(1e18);

double dist(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

double r, d;
int n;

int main(void) {
    // freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(nullptr);
    cin >> r >> d;
    cin >> n;

    int ans = 0;
    double x, y, r_i; 
    for (int i = 0; i < n; ++i) {
        cin >> x >> y >> r_i;
        double d_i = dist(x, y, 0, 0);
        if (d_i - r_i >= r - d && d_i + r_i <= r)
            ++ans;
    }
    cout << ans << endl;

    return 0;
}

