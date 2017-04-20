#include <bits/stdc++.h>
using namespace std;
#define PB push_back
typedef long long ll;
typedef long double ld;
const ll INF = ll(1e18);
ll T;

int main() {

    cin >> T;
    for (int i = 1; i <= T; ++i) {
        int res;
        vector<int> arr(3);
        for (int x: {0,1,2})
            cin >> arr[x];
        sort(arr.begin(), arr.end());
        printf("Case %d: %d\n", i, arr[1]);
    }

    return 0;
}
