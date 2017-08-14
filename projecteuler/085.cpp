#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Node {
    ll area;
    ll cnt;
};

ll rectangles(ll m, ll n) {
    return n * m * (n+1) * (m+1) / 4;
}

int main () {
    Node res = {0, 0};
    int lim = 2'000'000;
    int epsilon = 10000;

    for (int i = 1; i <= 2000; ++i) {
        for (int j = i; j <= 2000; ++j) {
            ll cnt = rectangles(i, j);
            if (cnt > lim + epsilon)
                break;
            if (abs(lim - cnt) < abs(lim - res.cnt))
                res = {i * j, cnt};
        }
    }
    cout << res.area << ' ' << res.cnt << endl;

    return 0;
}
