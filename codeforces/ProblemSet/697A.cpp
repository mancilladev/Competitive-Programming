#include <bits/stdc++.h>
using namespace std;
#define PB push_back
typedef long long ll;
typedef long double ld;
const ll INF = ll(1e18);
ll t, s, x;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> t >> s >> x;
    ll bark = t;
    while (bark+1 < x)
        bark += s;
    cout << (bark == x || (bark != t && bark+1 == x) ? "YES" : "NO") << endl;

    return 0;
}
