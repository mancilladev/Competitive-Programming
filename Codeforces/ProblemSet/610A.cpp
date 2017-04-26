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
    if (N%2 != 0)
        cout << "0\n";
    else
        cout << (N/2 - 1) / 2 << '\n';

    return 0;
}
