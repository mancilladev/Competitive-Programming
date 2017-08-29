#include <bits/stdc++.h>
using namespace std;
#define PB push_back
typedef long long ll;
typedef long double ld;
const ll INF = ll(1e18);
ll N, M;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> N;
    vector<ll> arr(N);
    for (int i = 0; i < N; ++i)
        cin >> arr[i];
    sort(arr.begin(), arr.end());

    ll res = 0;
    for (int i = 1; i < N; ++i)
        while (arr[i] <= arr[i-1])
            ++res, ++arr[i];
    cout << res << endl;

    return 0;
}
