#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <utility>
#define F first
#define S second
#define PB push_back
#define MP make_pair
typedef long long ll;
using namespace std;
const ll INF = ll(1e18);

ll maxSum(vector<ll> arr) {
    ll max_of_all = arr[0];
    ll max_pos = arr[0];
    ll max_neg = -arr[0];

    char sign = -1;
    for (int i = 1; i < arr.size(); ++i) {
        ll cur_pos = sign * arr[i];
        ll cur_neg = -sign * arr[i];

        max_pos = max(cur_pos, max_pos + cur_pos);
        max_neg = max(cur_neg, max_neg + cur_neg);
        max_of_all = max(max_of_all, max(max_pos, max_neg));

        sign = sign == 1 ? -1 : 1;
    }

    return max_of_all;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<ll> arr(N-1), vals(N);
    for (int i = 0; i < N; ++i)
        cin >> vals[i];
    for (int i = 0; i < N-1; ++i)
        arr[i] = abs(vals[i] - vals[i+1]);

    cout << maxSum(arr) << '\n';

    return 0;
}
