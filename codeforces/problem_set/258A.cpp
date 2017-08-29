#include <bits/stdc++.h>
using namespace std;
#define PB push_back
typedef long long ll;
typedef long double ld;
const ll INF = ll(1e18);
string s, res;

void solve() {
    res = s;
    for (int i = 0; i < s.size(); ++i)
        if (res[i] == '0') {
            res.erase(res.begin()+i);
            break;
        }
    if (res.size() == s.size())
        res.erase(res.begin());
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> s;
    solve();
    cout << res << '\n';

    return 0;
}
