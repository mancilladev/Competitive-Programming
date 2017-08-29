#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define PB push_back
#define MP make_pair
typedef long long ll;
typedef long double ld;
const ll INF = ll(1e18);

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    ll N, total = 0;
    cin >> N;
    vector<ll> arr(N);
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
        total += arr[i];
    }

    if (total%3 != 0) {
        cout << 0 << endl;
        return 0;
    }

    ll t = 0, res = 0, cur = 0;
    ll target = total/3;

    for (int i = 0; i < N-1; ++i) {
        cur += arr[i];
        if (cur == target) ++t;
        else if (cur == target*2) res += t;
    }

    if (target == 0)
        res = t * (t-1) / 2;

    cout << res << endl;

    return 0;
}
