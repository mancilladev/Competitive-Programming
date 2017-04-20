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
        ll a, b;
        cin >> a >> b;
        if (a > b)
            cout << '>';
        else if (a < b)
            cout << '<';
        else
            cout << '=';
        cout << '\n';
    }
    return 0;
}
