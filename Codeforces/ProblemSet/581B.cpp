#include <bits/stdc++.h>
using namespace std;
#define PB push_back
typedef long long ll;
typedef long double ld;
const ll INF = ll(1e18);
int N;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> N;
    vector<ll> arr(N);
    for (int i = 0; i < N; ++i)
        cin >> arr[i];
    ll highest = 0;
    vector<ll> change(N);
    for (int i = N-1; i >= 0; --i) {
        change[i] = max(0LL, highest - arr[i] + 1LL);
        highest = max(highest, arr[i]);
    }
    for (ll x: change)
        cout << x << ' ';
    cout << '\n';

    return 0;
}
