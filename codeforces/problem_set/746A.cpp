#include <bits/stdc++.h>
using namespace std;
#define PB push_back
typedef long long ll;
typedef long double ld;
const ll INF = ll(1e18);
ll a, b, c, res;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> a >> b >> c;
    res = 7 * min(a, min(b/2, c/4));
    cout << res << endl;

    return 0;
}
