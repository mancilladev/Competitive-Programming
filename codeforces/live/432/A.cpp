#include <bits/stdc++.h>
#define PB push_back
using namespace std;
typedef long long ll;
typedef long double ld;

ll n, k, t;
int main(void) {
    // freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(nullptr);
    cin >> n >> k >> t;
    if (t <= k)
        cout << t << endl;
    else if (t <= n)
        cout << k << endl;
    else
        cout << (n + k - t) << endl;
    return 0;
}
