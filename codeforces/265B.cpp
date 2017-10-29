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
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    int res = 0, h = 1;
    for (int i = 0; i < n-1; ++i) {
        res += abs(a[i] - h) + 1;
        if (a[i+1] < a[i]) res += a[i] - a[i+1];
        h = min(a[i], a[i+1]);
        ++res;
    }
    res += abs(a[n-1] - h) + 1;
    cout << res + 1 << endl;
    return 0;
}
