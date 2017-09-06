#include <bits/stdc++.h>
#define PB push_back
using namespace std;
typedef long long ll;
typedef long double ld;

int n, a[110];
int main(void) {
    // freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    int l = 0;
    for (int i = 1; i < n; ++i)
        if (abs(a[i] - a[(i+1)%n]) < abs(a[l] - a[(l+1)%n]))
            l = i;
    cout << l+1 << ' ' << ((l+2 > n) ? 1 : l+2) << endl;
    return 0;
}
