#include <bits/stdc++.h>
using namespace std;
#define PB push_back
typedef long long ll;
typedef long double ld;
const ll INF = ll(1e18);
const int MAX = (1e9);
int N, arr[MAX] {0};

ll calculate(ll d) {
    ll x = sqrt(d);
    ll y = 1;
    ll left, right;
    while (x < MAX) {
        left = x * x;
        right = 1 + d * y * y;
        if (left == right)
            return x;
        if (left < right)
            ++x;
        else
            ++y;
    }
    return 0;
}

int main() {
    vector<bool> isSqr(1007, 0);
    for (int i = 2; i * i <= 1000; ++i)
        isSqr[i*i] = 1;

    ll res = 1;
    for (int D = 2; D <= 1000; ++D)
        if (!isSqr[D])
            res = max(res, calculate(D)), cout << D << '\n';
    cout << "Solution: " << res << endl;

    return 0;
}
