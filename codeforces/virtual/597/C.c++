#include <iostream>
#include <vector>
#define MAXK 20
#define MAXN 200020
using namespace std;
int n, k, a[MAXN];
long long bit[MAXK][MAXN], ans[MAXN][MAXK];

auto inc(int lvl, int pos, auto val) {
    while (pos < 100010) {
        bit[lvl][pos] += val;
        pos += (pos & -pos);
    }
}

auto sum(int lvl, int pos) {
    long long cnt = 0;
    while (pos > 0) {
        cnt += bit[lvl][pos];
        pos -= (pos & -pos);
    }
    return cnt;
}

int main () {
    cin >> n >> k;
    ++k;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    for (int i = 1; i <= n; ++i)
        ans[i][1] = 1;
    for (int x = 2; x <= k; ++x) {
        for (int y = 1; y <= n; ++y) {
            ans[y][x] = sum(x-1, a[y]);
            inc(x-1, a[y], ans[y][x-1]);
        }
    }
    long long sol = 0;
    for (int i = 1; i <= n; ++i)
        sol += ans[i][k];
    cout << sol << '\n';

    return 0;
}
