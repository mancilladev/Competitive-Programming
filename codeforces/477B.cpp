#include <bits/stdc++.h>
#define PB push_back
using namespace std;
typedef long long ll;
typedef long double ld;
const ll INF = ll(1e18);

int main(void) {
    // freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(nullptr);
    string s;
    int k;
    int w[26];
    cin >> s >> k;

    int n = s.length();
    int maxi = 0;
    for (int i = 0; i < 26; ++i)
        cin >> w[i], maxi = max(maxi, w[i]);

    ll ans = 0;
    for (int i = 0; i < n; ++i)
        ans += (i+1) * w[s[i] - 'a'];
    for (int i = 0; i < k; ++i)
        ans += (n + i + 1) * maxi;
    cout << ans << endl;

    return 0;
}
