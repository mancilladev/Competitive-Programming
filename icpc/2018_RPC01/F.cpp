#include <bits/stdc++.h>
using namespace std;
typedef long double ld;

const int N = 407;
int n, k;
bool used[N][N];
ld mem[N][N];

ld solve(int n, int k) {
    if (k == 0) return 0;
    if (used[n][k]) return mem[n][k];

    used[n][k] = true;
    if (n == 0) {
        return mem[n][k] = 0.5 * (solve(0, k-1) + solve(1, k-1) - 1);
    }
    return mem[n][k] = 0.5 * (solve(n, k-1) + solve(n-1, k-1) + 1);
}

int main(void) {
    cin >> n >> k;
    cout << fixed << setprecision(15) << solve(n, k) << '\n';
    return 0;
}
