#include <bits/stdc++.h>
#define PB push_back
using namespace std;
typedef long long ll;
typedef long double ld;

int main(void) {
    // freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(nullptr);
    vector<int> isp(100, 1);
    for (int i = 2; i * i < 100; ++i) if (isp[i])
        for (int j = i * i; j < 100; j += i) isp[j] = 0;
    int n, m; cin >> n >> m;
    if (!isp[m]) return cout << "NO\n", 0;
    for (int i = n + 1; i < m; ++i)
        if (isp[i]) return cout << "NO\n", 0;
    cout << "YES\n";
    return 0;
}
