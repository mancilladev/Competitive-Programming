#include <bits/stdc++.h>
#define PB push_back
using namespace std;
typedef long long ll;
typedef long double ld;

int n, l[5], r[5];
int main(void) {
    // freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int a, b; cin >> a >> b;
        l[a]++;
        r[b]++;
    }
    cout << (min(l[0], l[1]) + min(r[0], r[1])) << endl;
    return 0;
}
