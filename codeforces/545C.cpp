#include <bits/stdc++.h>
#define PB push_back
using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 1e5 + 7;
int n;
int x[N], h[N];

int main(void) {
    // freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> x[i] >> h[i];
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (i == 0 || i + 1 == n) {
            ++cnt;
            continue;
        }
        if (x[i] - h[i] > x[i - 1]) ++cnt;
        else if (x[i] + h[i] < x[i + 1]) x[i] += h[i], ++cnt;
    }
    cout << cnt << '\n';
    return 0;
}
