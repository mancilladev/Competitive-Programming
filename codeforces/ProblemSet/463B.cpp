#include <bits/stdc++.h>
using namespace std;
#define PB push_back
typedef long long ll;
typedef long double ld;
const ll INF = ll(1e18);
ll T, N;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> N;
    vector<ll> arr(N+1, 0);
    for (int i = 1; i <= N; ++i)
        cin >> arr[i];
    int res = 0;
    int energy = 0;
    for (int i = 0; i < N; ++i) {
        energy += arr[i] - arr[i+1];
        if (energy < 0)
            res += abs(energy), energy = 0;
    }
    cout << res << '\n';

    return 0;
}
