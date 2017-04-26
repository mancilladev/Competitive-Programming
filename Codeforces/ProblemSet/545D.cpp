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
    vector<ll> arr(N);
    for (int i = 0; i < N; ++i)
        cin >> arr[i];
    sort(arr.begin(), arr.end());
    ll time = 0;
    int cnt = 0;
    for (ll x: arr) {
        if (time <= x)
            ++cnt, time += x;
    }
    cout << cnt << '\n';

    return 0;
}
