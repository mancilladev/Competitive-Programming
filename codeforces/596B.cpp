#include <bits/stdc++.h>
using namespace std;
#define error(x) cerr << #x << " = " << x << endl;
#define mt make_tuple
#define eb emplace_back
#define pb push_back
typedef long long ll;
typedef long double ld;

int main(void) {
    // freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(nullptr);
    int n; cin >> n;
    ll res = 0, sum = 0;
    for (int i = 0, x; i < n; ++i) {
        cin >> x;
        if (sum != x) res += abs(sum - x), sum = x;
    }
    cout << res << endl;
    return 0;
}
