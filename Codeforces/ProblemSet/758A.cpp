#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <utility>
using namespace std;
#define F first
#define S second
#define PB push_back
#define MP make_pair
typedef long long ll;
const ll INF = ll(1e18);

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<int> arr(N);
    for (int i = 0; i < N; ++i)
        cin >> arr[i];

    sort(arr.begin(), arr.end());

    ll ans = 0;
    for (int i = 0; i < N-1; ++i)
        ans += arr[N-1] - arr[i];
    cout << ans << '\n';

    return 0;
}
