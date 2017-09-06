#include <bits/stdc++.h>
#define PB push_back
using namespace std;
typedef long long ll;
typedef long double ld;

int x, a[5][5];
int main(void) {
    // freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(nullptr);
    for (int i = 1; i <= 3; ++i) for (int j = 1; j <= 3; ++j) a[i][j] = 1;
    for (int i = 1; i <= 3; ++i) for (int j = 1; j <= 3; ++j) {
        cin >> x;
        if (x&1) {
            a[i][j] = !a[i][j];
            a[i][j-1] = !a[i][j-1];
            a[i][j+1] = !a[i][j+1];
            a[i-1][j] = !a[i-1][j];
            a[i+1][j] = !a[i+1][j];
        }
    }
    for (int i = 1; i <= 3; ++i) {
        for (int j = 1; j <= 3; ++j)
            cout << a[i][j];
        cout << '\n';
    }
    return 0;
}
