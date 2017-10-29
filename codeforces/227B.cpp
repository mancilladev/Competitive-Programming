#include <bits/stdc++.h>
#define PB push_back
using namespace std;
typedef long long ll;
typedef long double ld;

const int N = (int)1e5 + 7;
int n, m, pos[N];
ll l, r;

int main(void) {
    // freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(nullptr);
    cin >> n;
    for (int x, i = 1; i <= n; ++i) {
        cin >> x;
        pos[x] = i;
    }
    cin >> m;
    for (int x, i = 0; i < m; ++i) {
        cin >> x;
        l += pos[x];
        r += n - pos[x] + 1;
    }
    cout << l << ' ' << r << '\n';
    return 0;
}
