#include <bits/stdc++.h>
using namespace std;
#define PB push_back
typedef long long ll;
typedef long double ld;
const ll INF = ll(1e18);
const int MAX = (1e8);
vector<int> isp(MAX, 1);
vector<int> v {3, 7, 109, 673};
int sum = 3 + 7 + 109 + 673;

int concat(int x, int y) {
    int times = 1;
    while (times <= y)
        times *= 10;
    return x * times + y;
}

bool solves(int p) {
    for (int x: v) {
        int a, b;
        a = concat(x, p);
        b = concat(p, x);
        if (!isp[a] || !isp[b])
            return false;
    }
    return true;
}

int main() {
    for (int i = 2; i * i < MAX; ++i) if (isp[i])
        for (int j = i * i; j < MAX; j += i) isp[j] = 0;

    for (int p = 2; p < 99999; ++p)
        if (isp[p] && find(v.begin(), v.end(), p) == v.end() && solves(p))
            cout << p << ' ' << sum + p << '\n';

    return 0;
}

