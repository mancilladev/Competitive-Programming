#include <bits/stdc++.h>
using namespace std;
#define error(x) cerr << #x << " = " << x << endl;
#define mt make_tuple
#define eb emplace_back
#define pb push_back
typedef long long ll;
typedef long double ld;

int main(void) {
    // freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(nullptr);
    int n, k; cin >> n >> k;
    int a[n+7] {1};
    int g = k;
    for (int i = 0; i < k; ++i) {
        if (~i&1)
            a[i+1] = a[i] + g;
        else
            a[i+1] = a[i] - g;
        g--;
    }
    for (int i = k + 1; i < n; ++i) a[i] = i + 1;
    for (int i = 0; i < n; ++i) cout << a[i] << ' ';
    cout << endl;
    return 0;
}
