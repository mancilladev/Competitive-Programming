#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define PB push_back
#define MP make_pair
typedef long long ll;
typedef long double ld;
const ll INF = ll(1e18);
ll A, B;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> A >> B;
    ll res = 0;
    while (A <= B)
        A *= 3, B *= 2, ++res;
    cout << res << endl;

    return 0;
}
