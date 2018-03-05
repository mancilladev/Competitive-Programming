#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
int n, k, d, dp[1007][2];

int f(int sum, bool usedd) {
    if (dp[sum][usedd] != -1) return dp[sum][usedd];
    
    if (sum >= n) return dp[sum][usedd] = (sum == n && usedd);
    
    int res = 0;
    for (int i = 1; i <= k; ++i) {
        res += f(sum + i, (i >= d) | usedd);
        res %= MOD;
    }
    
    return dp[sum][usedd] = res;
}

int main(void) {
    memset(dp, -1, sizeof(dp));
    cin >> n >> k >> d;
    cout << f(0, 0) << endl;
    return 0;
}
