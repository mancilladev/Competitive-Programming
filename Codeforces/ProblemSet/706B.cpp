#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define PB push_back
#define MP make_pair
typedef long long ll;
const ll INF = ll(1e18);
int N, Q;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> N;
    vector<int> arr(N);
    for (int i = 0; i < N; ++i)
        cin >> arr[i];
    sort(arr.begin(), arr.end());

    cin >> Q;
    while (Q--) {
        int k; cin >> k;
        int res = upper_bound(arr.begin(), arr.end(), k) - arr.begin();
        cout << res << '\n';
    }

    return 0;
}
