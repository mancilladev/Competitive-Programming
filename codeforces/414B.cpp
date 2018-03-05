#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;
int n, dp[2007][2007];

int f(int k, int last) {
    if (k == 0) return 1;
    if (dp[k][last]) return dp[k][last];
    
    int res = 0;
    for (int i = last; i <= n; i += last) {
        res += f(k-1, i);
        res %= MOD;
    }
    return dp[k][last] = res;
}

int main(void) {
    int k;
    cin >> n >> k;
    cout << f(k, 1) << '\n';
    return 0;   
}
