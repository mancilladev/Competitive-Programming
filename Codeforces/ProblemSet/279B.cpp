#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define PB push_back
#define MP make_pair
typedef long long ll;
typedef long double ld;
const ll INF = ll(1e18);
ll N, T;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> N >> T;
    vector<int> arr(N);
    for (int i = 0; i < N; ++i)
        cin >> arr[i];

    int p = 0;
    int res = 0;
    ll curt = 0;
    for (int i = 0; i < N && p < N; ++i) {
        curt += arr[i];
        while (p < N && curt > T)
            curt -= arr[p], ++p;
        res = max(res, i - p + 1);
    }
    cout << res << endl;

    return 0;
}
