#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define PB push_back
#define MP make_pair
typedef long long ll;
typedef long double ld;
const ll INF = ll(1e18);

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    vector<int> a(4);
    for (int i = 0; i < 4; ++i)
        cin >> a[i];
    string s;
    cin >> s;
    ll res = 0;
    for (int i = 0; i < s.size(); ++i)
        res += a[s[i] - '0' - 1];
    cout << res << '\n';

    return 0;
}
