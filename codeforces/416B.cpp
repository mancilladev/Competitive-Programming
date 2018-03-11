#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
int n, m, a[N][7], cnt[N], last[N];

int main (void) {
    cin >> m >> n;
    for (int j = 1; j <= m; ++j) {
        for (int i = 1; i <= n; ++i) {
            cin >> a[j][i];
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cnt[j] = max(cnt[j-1], cnt[j]) + a[j][i];
        }
    }
    for (int j = 1; j <= m; ++j) cout << cnt[j] << ' ';
    cout << '\n';
    return 0;
}
