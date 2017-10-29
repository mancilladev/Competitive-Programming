#include <bits/stdc++.h>
#define PB push_back
using namespace std;
typedef long long ll;
typedef long double ld;

int main(void) {
    // freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(nullptr);
    int n; cin >> n;
    if (n == 0) return cout << "0 0 0\n", 0;
    int a = 0, b = 1, tmp;
    while (a + b != n) {
        tmp = a; a = b; b = b + tmp;
    }
    cout << 0 << ' ' << a << ' ' << b << '\n';
    return 0;
}
