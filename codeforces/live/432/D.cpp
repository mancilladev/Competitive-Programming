#include <bits/stdc++.h>
#define PB push_back
using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 1e6 + 7;
const ll INF = 1e17;
ll n, x, y;
ll a[N], f[N], c[N];

int main(void) {
    // freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(nullptr);
    cin >> n >> x >> y;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        f[a[i]]++;
    }
    for (int i = 1; i < N; ++i) {
        c[i] = c[i - 1] + f[i];
        s[i] = s[i - 1] + i * f[i];
    }
    ll ans = INF;
    return 0;
}
