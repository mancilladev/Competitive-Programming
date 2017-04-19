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
    vector<int> arr(7, 0);
    for (int day = 0; day < N; ++day)
        ++arr[day%7];

    ll dmin = INF;
    ll dmax = -INF;

    for (int i = 0; i < 7; ++i) {
        int j = (i+1)%7;
        dmin = min(dmin, (ll)arr[i] + arr[j]);
        dmax = max(dmax, (ll)arr[i] + arr[j]);
    }

    cout << dmin << ' ' << dmax << endl;

    return 0;
}
