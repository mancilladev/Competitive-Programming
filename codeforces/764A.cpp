#include <bits/stdc++.h>
using namespace std;
#define PB push_back
typedef long long ll;
typedef long double ld;
const ll INF = ll(1e18);
ll n, m, z;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> n >> m >> z;
    ll res = 0;
    for (int i = 1; i <= z; ++i) {
        if (i%m == 0 && i%n == 0)
            ++res;
    }
    cout << res << endl;

    return 0;
}
