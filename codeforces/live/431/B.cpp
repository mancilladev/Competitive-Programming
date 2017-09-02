#include <bits/stdc++.h>
#define PB push_back
using namespace std;
typedef long long ll;
typedef long double ld;
const ll INF = ll(1e18);

int n;
ld y[1010];

int check(double k) {
    int new_line = 0;
    for (int i = 2; i <= n; ++i) {
        if (y[i] - y[1] == k * (i - 1)) continue;
        if(new_line == 0) new_line = i;
        if (y[i] - y[new_line] != k * (i - new_line))
            return 0;
    }
    return new_line;
}

int main(void) {
    // freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> y[i];
    double k1 = y[2] - y[1], k2 = (y[3] - y[1]) / 2, k3 = y[3] - y[2];
    if (check(k1) || check(k2) || check(k3)) puts("Yes");
    else puts("No");

    return 0;
}
