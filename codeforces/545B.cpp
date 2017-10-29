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
    string s, t; cin >> s >> t;
    string ans;
    int x = 0;
    for (int i = 0; i < (int) s.length(); ++i) {
        if (s[i] == t[i]) ans += s[i];
        else ans += (x&1 ? s[i] : t[i]), ++x;
    }
    if (x&1) cout << "impossible\n";
    else cout << ans << '\n';
    return 0;
}
