#include <bits/stdc++.h>
#define PB push_back
using namespace std;
typedef long long ll;
typedef long double ld;

int N, a, b;
int main(void) {
    // freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(nullptr);
    cin >> N;
    int l = 0, r = 0, diff = 0;
    for (int i = 0; i < N; ++i) {
        cin >> a >> b;
        l += a;
        r += b;
        if ((a&1) != (b&1)) diff = 1;
    }
    if (!(l&1 || r&1)) cout << 0 << endl;
    else if ((l&1) != (r&1)) cout << -1 << endl;
    else cout << (diff ? 1 : -1) << endl;
    return 0;
}
