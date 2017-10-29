#include <bits/stdc++.h>
using namespace std;
#define PB push_back
typedef long long ll;
typedef long double ld;
const ll INF = ll(1e18);
ll N;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> N;
    string s = to_string(N);
    ll res = 0;
    for (ll i = 1; i < s.size(); ++i)
        res += (9 * pow(10, i-1)) * i;
    res += (N - pow(10, s.size()-1) + 1) * s.size();
    cout << res << endl;

    return 0;
}
