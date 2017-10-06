#include <bits/stdc++.h>
#define PB push_back
using namespace std;
typedef long long ll;
typedef long double ld;

const int MOD = 1<<30, MAX = 1e6+7;
int a, b, c, mem[MAX];

int divisors(ll x) {
    if (!mem[x]) {
        int cnt = 1;
        for (int d = 2; d <= x; ++d) {
            int exponent = 1;
            while (x%d == 0)
                ++exponent, x /= d;
            cnt *= exponent;
        }
        mem[x] = cnt;
    }
    return mem[x];
}

int main(void) {
    // freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(nullptr);
    for (int i = 0; i < MAX; ++i) mem[i] = 0;

    cin >> a >> b >> c;
    ll sum = 0;
    for (int i = 1; i <= a; ++i)
        for (int j = 1; j <= b; ++j)
            for (int k = 1; k <= c; ++k)
            sum += divisors(i * j * k), sum %= MOD;
    cout << sum << '\n';
    return 0;
}
