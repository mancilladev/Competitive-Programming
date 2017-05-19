#include <bits/stdc++.h>
using namespace std;
#define PB push_back
typedef long long ll;
typedef long double ld;
const ll INF = ll(1e18);
ll T, N;

int main() {
    cin >> T;
    for (int tt = 1; tt <= T; ++tt) {
        cin >> N;
        ll cur, res = 0;
        for (int i = 0; i < N; ++i)
            cin >> cur, res = max(res, cur);
        printf("Case %d: %lld\n", tt, res);
    }

    return 0;
}
