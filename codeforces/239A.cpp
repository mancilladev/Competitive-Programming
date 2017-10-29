#include <bits/stdc++.h>
#define PB push_back
using namespace std;
typedef long long ll;
typedef long double ld;

int y, k, n;
int main(void) {
    // freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(nullptr);
    cin >> y >> k >> n;
    int ok = 0, i = k;
    while (i <= y) i += k;
    for (; i <= n; i += k) {
        ok = 1;
        cout << i-y << ' ';
    }
    if (!ok) cout << -1;
    cout << '\n';
    return 0;
}
