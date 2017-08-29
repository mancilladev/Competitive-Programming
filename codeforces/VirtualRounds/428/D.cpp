#include <bits/stdc++.h>
#define PB push_back
using namespace std;
typedef long long ll;
typedef long double ld;
const ll INF = ll(1e18);

const int MOD = (int)1e9 + 7;
const int N = 200000 + 7;
ll a[N];
ll n;
ll ans = 0;

void func(int i, int k, ll val) {
    ans += (k * val) % MOD;
    ans %= MOD;
    for (int j = i + 1; j < n; ++j) {
        int t = __gcd(val, a[j]);
        if (t > 1)
            func(j, k + 1, t);
    }
}

int main(void) {
    // freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < n; ++i)
        if (a[i] != 1)
            func(i, 1, a[i]);
    cout << ans << endl;

    return 0;
}
