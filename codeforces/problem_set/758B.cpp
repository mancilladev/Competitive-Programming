#include <bits/stdc++.h>
#define PB push_back
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef long double ld;

const int INF = 1e9 + 7;
int n, m, l, r;
int maxL1 = 0, minR1 = INF;
int maxL2 = 0, minR2 = INF;
int main(void) {
    // freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> l >> r;
        maxL1 = max(maxL1, l);
        minR1 = min(minR1, r);
    }
    cin >> m;
    for (int i = 0; i < m; ++i) {
        cin >> l >> r;
        maxL2 = max(maxL2, l);
        minR2 = min(minR2, r);
    }
    int ans = max(maxL2 - minR1, maxL1 - minR2);
    cout << max(0, ans) << endl;
    return 0;
}
