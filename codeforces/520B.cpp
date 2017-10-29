#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define PB push_back
#define MP make_pair
typedef long long ll;
const ll INF = ll(1e18);
ll N, M;

ll calc(ll n, ll m) {
    if (n >= m) return n - m;
    if (m%2 == 0) return 1 + calc(n, m/2);
    return 2 + calc(n, (m+1)/2);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> N >> M;
    cout << calc(N, M) << '\n';

    return 0;
}
