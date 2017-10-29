#include <bits/stdc++.h>
#define PB push_back
using namespace std;
typedef long long ll;
typedef long double ld;
const ll INF = ll(1e18);

int n, m;
int a[101];
int main(void) {
    // freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a, a+n);
    int ans = 0, sum = 0;
    for (int i = 0; i < m; ++i)
        sum -= a[i], ans = max(ans, sum);
    cout << ans << endl;

    return 0;
}
