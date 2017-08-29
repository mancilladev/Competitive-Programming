#include <bits/stdc++.h>
using namespace std;
#define PB push_back
typedef long long ll;
typedef long double ld;
const ll INF = ll(1e18);
ll T, N, K;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> N >> K;
    vector<ll> arr(N);
    for (int i = 0; i < N; ++i)
        cin >> arr[i];
    ll cur = 0;
    for (int i = 0; i < K; ++i)
        cur += arr[i];
    int res = 1;
    ll minsum = cur;
    for (int i = K; i < N; ++i) {
        cur += arr[i];
        cur -= arr[i-K];
        if (cur < minsum) {
            minsum = cur;
            res = i-K+2;
        }

    }
    cout << res << '\n';

    return 0;
}
