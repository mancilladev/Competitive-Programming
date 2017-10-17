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
    for (int i = 0; i < k; ++i)
        cout << n - i << ' ';
    for (int i = k; i < n; ++i)
        cout << i - k + 1 << ' ';
    cout << endl;
    return 0;
}
