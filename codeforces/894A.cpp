#include <bits/stdc++.h>
using namespace std;

string s;
int dp[107][7];

int f(int x, int k) {
    if (k == 3 || x == (int)s.size()) return k == 3;
    if (dp[x][k] != -1) return dp[x][k];
    
    bool equal = (k != 1 && s[x] == 'Q') || (k == 1 && s[x] == 'A');
    
    int res = f(x+1, k);
    if (equal) res += f(x+1, k+equal);
    return dp[x][k] = res;
}

int main(void) {
    memset(dp, -1, sizeof dp);
    cin >> s;
    cout << f(0, 0) << '\n';
    return 0;
}
