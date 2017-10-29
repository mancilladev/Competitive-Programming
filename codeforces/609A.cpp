#include <bits/stdc++.h>
using namespace std;
#define error(x) cerr << #x << " = " << x << endl
#define mt make_tuple
#define eb emplace_back
#define pb push_back
typedef long long ll;
typedef long double ld;

int main(void) {
    // freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(nullptr);
    int n, m; cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a.begin(), a.end(), greater<int>());
    int res = 0;
    for (int i = 0; i < n; ++i) {
        if (m > 0) m -= a[i], ++res;
    }
    cout << res << endl;
    return 0;
}
