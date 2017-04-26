#include <bits/stdc++.h>
using namespace std;
#define PB push_back
typedef long long ll;
typedef long double ld;
const ll INF = ll(1e18);

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;
    vector<int> arr(N);
    for (int i = 0; i < N; ++i)
        cin >> arr[i];
    int res = 0;
    for (int i = 0; i < N-1; ++i)
        res = max(res, arr[i]-arr[i+1]-K);
    cout << res << '\n';

    return 0;
}
