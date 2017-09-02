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
    int n, a, b;
    cin >> n >> a >> b;
    string s;
    cin >> s;
    cout << abs((s[--a] - '0') - (s[--b] - '0')) << '\n';

    return 0;
}
