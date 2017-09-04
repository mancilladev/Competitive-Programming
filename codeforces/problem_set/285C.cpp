#include <bits/stdc++.h>
#define PB push_back
using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 3e5 + 7;
int a[N];
int n;
ll ans = 0;

int main(void) {
    // freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(nullptr);
    int n; cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a, a+n);
    for (int i = 0; i < n; ++i)
        ans += abs(a[i] - 1 - i);
    cout << ans << endl;
    return 0;
}
