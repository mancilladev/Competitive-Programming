#include <bits/stdc++.h>
#define PB push_back
using namespace std;
typedef long long ll;
typedef long double ld;

int n;
int m[3][2], cnt[3];
int main(void) {
    // freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < 3; ++i) {
        cin >> m[i][0] >> m[i][1];
        n -= m[i][0];
        cnt[i] += m[i][0];
    }
    for (int i = 0; i < 3; ++i) {
        int x = min(n, m[i][1] - m[i][0]);
        n -= x;
        cnt[i] += x;
    }
    for (int i = 0; i < 3; ++i)
        cout << cnt[i] << ' ';
    cout << endl;
    return 0;
}
