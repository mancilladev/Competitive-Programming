#include <bits/stdc++.h>
#define PB push_back
using namespace std;
typedef long long ll;
typedef long double ld;
const ll INF = ll(1e18);

const int MOD = (int)1e9 + 7;
const int N = 1010100;
ll a[N], cnt[N], dp[N], power[N];
ll ans = 0, maxi = 0;
ll n;

int main(void) {
    // freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(nullptr);
    cin >> n;

    // powers
    power[0] = 1;
    for (ll i = 1; i < N; ++i)
        power[i] = (power[i-1] * 2) % MOD;

    // common divisors
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
        maxi = max(maxi, a[i]);
        for (ll j = 2; j * j <= a[i]; ++j) if (a[i]%j == 0) {
            cnt[j]++;
            if (a[i]/j != j)
                cnt[a[i]/j]++;
        }
        cnt[a[i]]++;
    }

    // step 2
    for (int i = maxi; i >= 2; --i) {
        ll minus = 0;
        if (cnt[i] > 0) {
            if (i <= maxi/2)
                for (ll j = i * 2; j > 0 && j <= maxi; j += i)
                    minus += dp[i];
            dp[i] = (cnt[i] * power[cnt[i] - 1]) % MOD;
            dp[i] -= minus;
            dp[i] = (dp[i]%MOD + MOD) % MOD;
            ans = (ans + (dp[i] * i)%MOD) % MOD;
        } else {
            dp[i] = 0;
        }
    }

    cout << ans << endl;

    return 0;
}

