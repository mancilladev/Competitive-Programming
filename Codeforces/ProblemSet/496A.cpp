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

    int pos = 1;
    int diff = arr[2] - arr[0];
    for (int i = 2; i < N-1; ++i) {
        int curd = arr[i+1] - arr[i-1];
        if (curd < diff)
            diff = curd, pos = i;
    }
    arr.erase(arr.begin()+pos);

    ll res = 0;
    for (int i = 1; i < arr.size(); ++i)
        res = max(res, arr[i]-arr[i-1]);
    cout << res << endl;

    return 0;
}
