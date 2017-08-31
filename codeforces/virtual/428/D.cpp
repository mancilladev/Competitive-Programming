#include <bits/stdc++.h>
#define PB push_back
using namespace std;
typedef long long ll;
typedef long double ld;
const ll INF = ll(1e18);
const ll MOD = (ll)1e9 + 7;

ll sub(ll x, ll y) {
    x -= y;
    if (x < 0)
        x += MOD;
    return x;
}

ll add(ll x, ll y) {
    return (x + y) % MOD;
}

ll mult(ll x, ll y) {
    return (x * y) % MOD;
}

const int N = (int)1e6 + 7;
int cnt[N] {0};
ll power[N];
ll a[N];

int main(void) {
    // freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(nullptr);

    power[0] = 1;
    for (int i = 1; i < N; ++i)
        power[i] = mult(power[i - 1], 2);

    int n, x;
    cin >> n;
    while (n--)
        cin >> x, cnt[x]++;
    for (int i = 1; i < N; ++i) {
        int y = 0;
        for (int j = i; j < N; j += i)
            y += cnt[j];
        if (y == 0) continue;
        a[i] = mult(y, power[y - 1]);
    }

    ll ans = 0;
    for (int x = N - 1; x > 1; --x) {
        for (int y = 2 * x; y < N; y += x)
            a[x] = sub(a[x], a[y]);
        ans = add(ans, mult(x, a[x]));
    }
    printf("%lld\n", ans);

    return 0;
}
