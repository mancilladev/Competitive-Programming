#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll MAX = (1e9);

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
    vector<bool> is_square(1007, 0);
    for (int i = 2; i * i <= 1000; ++i)
        is_square[i*i] = 1;

    ll res = 1;
    for (int D = 2; D <= 1000; ++D)
        if (!is_square[D])
            res = max(res, calculate(D)), cout << D << ' ' << calculate(D) << '\n';
    cout << "Solution: " << res << endl;

    return 0;
}
