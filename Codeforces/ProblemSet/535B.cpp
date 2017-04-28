#include <bits/stdc++.h>
using namespace std;
#define PB push_back
typedef long long ll;
typedef long double ld;
const ll INF = ll(1e18);
ll T, N;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    string s;
    cin >> s;
    ll res = pow(2, s.size()) - 1;
    for (int i = s.size()-1; i >= 0; --i) {
        if (s[i] == '7')
            res += pow(2, s.size()-(i+1));
    }
    cout << res << '\n';

    return 0;
}
