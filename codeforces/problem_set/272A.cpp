#include <bits/stdc++.h>
#define PB push_back
using namespace std;
typedef long long ll;
typedef long double ld;

int n, sum = 0;
int main(void) {
    // freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(nullptr);
    cin >> n;
    for (int x, i = 0; i < n; ++i) {
        cin >> x;
        sum += x;
    }
    ++n;
    int ans = 0;
    for (int i = 1; i <= 5; ++i)
        if ((i + sum - 1)%n != 0)
            ++ans;
    cout << ans << '\n';
    return 0;
}
