#include <bits/stdc++.h>
using namespace std;
#define PB push_back
typedef long long ll;
typedef long double ld;
const ll INF = ll(1e18);
ll T, N;

ll calc(int p, int t) {
    return max(3.0*p/10.0, p-p/250.0*t);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (calc(a,c) > calc(b,d))
        cout << "Misha\n";
    else if (calc(a,c) < calc(b,d))
        cout << "Vasya\n";
    else
        cout << "Tie\n";

    return 0;
}
