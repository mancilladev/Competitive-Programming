#include <bits/stdc++.h>
using namespace std;
#define PB push_back
typedef long long ll;
typedef long double ld;
const ll INF = ll(1e18);
const int MIN = (1e3), MAX = (1e4), K = 6;
vector<vector<int> >  poly(K);
vector<int> arr(K);

int calculate(int n, int f) {
    if (f == 0)
        return n * (n + 1) / 2;
    if (f == 1)
        return n * n;
    if (f == 2)
        return n * (3 * n - 1) / 2;
    if (f == 3)
        return n * (2 * n - 1);
    if (f == 4)
        return n * (5 * n - 3) / 2;
    return n * (3 * n - 2);
}

bool check() {
    unordered_set<int> l, r;
    for (int x: arr) {
        l.insert(x/100);
        r.insert(x%100);
        if (x/100 == x%100)
            return false;
    }
    return l == r;
}

bool solve(int y) {
    if (y == K)
        return check();

    for (int x: poly[y]) {
        arr[y] = x;
        if (solve(y+1))
            return true;
    }

    return false;
}

int main() {
    for (int x = 1; calculate(x, 0) < MAX; ++x) {
        for (int y = 0; y < K; ++y) {
            int num = calculate(x, y);
            if (num >= MIN && num <= MAX)
                poly[y].PB(num);
        }
    }

    solve(0);

    int res = 0;
    for (int x: arr)
        res += x, cout << x << '\n';
    cout << res << endl;

    return 0;
}
