#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <cmath>
using namespace std;
#define F first
#define S second
#define PB push_back
#define MP make_pair
typedef long long ll;
const ll INF = ll(1e18);

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    string S; cin >> S;
    int N = S.size();
    vector<ll> dp(N);
    dp[N-1] = 0;

    for (int i = N-2; i >= 0; --i)
        dp[i] = dp[i+1] + (S[i] == S[i+1] ? 1 : 0);

    int M; cin >> M;
    while (M--) {
        int l, r; cin >> l >> r;
        cout << dp[l-1] - dp[r-1] << '\n';
    }

    return 0;
}
