#include <bits/stdc++.h>
using namespace std;
#define PB push_back
typedef long long ll;
typedef long double ld;
const ll INF = ll(1e18);
ld a, b, c;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> a >> b >> c;
    if (c == 0) {
        if (b == a) cout << "YES\n";
        else cout << "NO\n";
    }
    else {
        ld k = (b - a) / c;
        if (k >= 0 && k == (ll)k) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}
