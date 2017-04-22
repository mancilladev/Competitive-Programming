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

    ll n, m;
    cin >> n >> m;
    if (n == 1)
        cout << 1;
    else if (m > n/2)
        cout << m-1;
    else
        cout << m+1;
    cout << '\n';

    return 0;
}
