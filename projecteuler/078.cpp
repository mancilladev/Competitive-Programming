#include <bits/stdc++.h>
using namespace std;
#define PB push_back
typedef long long ll;

int gpn(int n) {
    // generalized pentagonal number
    return n * (3 * n - 1) / 2;
}

int main(int argc, char const *argv[]) {
    vector<int> p, g;
    p.PB(1); g.PB(0);

    for (int i = 1; i < 10000; ++i) {
        g.PB(gpn(i));
        g.PB(gpn(-i));
    }

    int n = 0;
    while (p[n]%1'000'000) {
        p.PB(0);
        ++n;

        for (int k = 1; g[k] <= n; ++k) {
            int sign = ((k-1) % 4 < 2) ? 1 : -1;
            p[n] += sign * p[n - g[k]];
            p[n] %= 10'000'000;
        }
    }

    cout << ' ' << n << ' ' << p[n] << endl;

    return 0;
}
