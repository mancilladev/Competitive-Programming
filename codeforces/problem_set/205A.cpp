#include <bits/stdc++.h>
#define PB push_back
using namespace std;
typedef long long ll;
typedef long double ld;

int main(void) {
    // freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(nullptr);
    int n; cin >> n;
    int mini = 1e9 + 7;
    int ans = 0;
    int good = 1;
    for (int x, i = 0; i < n; ++i) {
        cin >> x;
        if (x == mini)
            good = 0;
        if (x < mini)
            good = 1, mini = x, ans = i + 1;
    }
    if (good) cout << ans << '\n';
    else cout << "Still Rozdil\n";
    return 0;
}
