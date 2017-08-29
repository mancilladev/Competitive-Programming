#include <bits/stdc++.h>
using namespace std;
#define PB push_back
typedef long long ll;
typedef long double ld;
const ll INF = ll(1e18);
ll T, N;

struct Col {
    ll l;
    ll r;
} ;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> N;
    vector<Col> arr(N);
    Col sum {0, 0};
    for (int i = 0; i < N; ++i) {
        cin >> arr[i].l >> arr[i].r;
        sum.l += arr[i].l;
        sum.r += arr[i].r;
    }
    int res = 0;
    ll beauty = abs(sum.l - sum.r);
    for (int i = 0; i < N; ++i) {
        Col col = {sum.l-arr[i].l+arr[i].r, sum.r-arr[i].r+arr[i].l};
        ll possible = abs(col.l-col.r);
        if (possible > beauty)
            beauty = possible, res = i+1;
    }
    cout << res << '\n';

    return 0;
}
