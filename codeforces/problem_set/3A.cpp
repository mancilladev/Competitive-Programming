#include <bits/stdc++.h>
#define PB push_back
using namespace std;
typedef long long ll;
typedef long double ld;
const ll INF = ll(1e18);

int main(void) {
    // freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(nullptr);
    string s, t;
    cin >> s >> t;
    int x = (t[0] - 'a') - (s[0] - 'a');
    int y = (t[1] - '0') - (s[1] - '0');
    cout << max(abs(x), abs(y)) << '\n';

    while (x || y) {
        if (x > 0) cout << 'R';
        if (x < 0) cout << 'L';
        if (y > 0) cout << 'U';
        if (y < 0) cout << 'D';
        cout << '\n';
        x += (x<0) - (x>0);
        y += (y<0) - (y>0);
    }

    return 0;
}
