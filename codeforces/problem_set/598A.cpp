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

    cin >> T;
    while (T--) {
        cin >> N;
        ll res = N*(N+1)/2;
        res -= 2 * (pow(2,(int)log2((int)N)+1)-1);
        cout << res << '\n';
    }

    return 0;
}
