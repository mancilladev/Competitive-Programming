#include <bits/stdc++.h>
#define PB push_back
using namespace std;
typedef long long ll;
typedef long double ld;

int a, b, N;

int solve() {
    for (int i = 0; i <= 9; ++i)
        if ((a*10 + i)%b == 0)
            return a * 10 + i;
    return -1;
}

int main(void) {
    // freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(nullptr);
    cin >> a >> b >> N;
    int x = solve();
    cout << x;
    if (x != -1) while (--N) cout << 0;
    cout << endl;
    return 0;
}
