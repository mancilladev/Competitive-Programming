#include <bits/stdc++.h>
using namespace std;
#define error(x) cerr << #x << " = " << x << endl;
#define mt make_tuple
#define eb emplace_back
#define pb push_back
typedef long long ll;
typedef long double ld;

int n, m;
int main(void) {
    // freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(nullptr);
    cin >> n >> m;
    if (m < n-1 || m > (n+1) * 2)
        return cout << -1 << endl, 0;

    if (m == n-1) cout << 0;
    if (m == n-1 || m == n) {
        for (int i = 0; i < m; ++i)
            cout << 10;
        cout << '\n';
        return 0;
    }
    
    int t = m - (n + 1);
    for (int i = 0; i < n; ++i) {
        if (i < t) cout << 11;
        else cout << 1;
        cout << 0;
    }
    if (m == (n+1)*2) cout << 11;
    else cout << 1;
    cout << '\n';
    return 0;
}
