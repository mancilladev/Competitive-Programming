#include <bits/stdc++.h>
using namespace std;
#define PB push_back
typedef long long ll;
typedef long double ld;
const ll INF = ll(1e18);
ll T, N, K, f, t, cur;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> N >> K;
    ll res = -INF;
    for (int i = 0; i < N; ++i) {
        cin >> f >> t;
        cur = (t > K ? (f - (t - K)) : f);
        res = max(res, cur);
    }
    cout << res << '\n';

    return 0;
}
