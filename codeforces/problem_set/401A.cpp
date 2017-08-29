#include <bits/stdc++.h>
using namespace std;
#define PB push_back
typedef long long ll;
typedef long double ld;
const ll INF = ll(1e18);

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    ll N, X;
    cin >> N >> X;
    int sum = 0, tmp;
    for (int i = 0; i < N; ++i)
        cin >> tmp, sum += tmp;
    cout << abs(sum/X) + (sum%X != 0 ? 1 : 0) << '\n';

    return 0;
}
