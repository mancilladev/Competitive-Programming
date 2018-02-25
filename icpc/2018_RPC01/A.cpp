#include <bits/stdc++.h>
using namespace std;

const int N = 107;
int n, h[N], r[N], t[N], cur[N];

bool hasSun(int x) {
    if (r[x] > t[x]) return r[x] < cur[x] || cur[x] < t[x];
    return r[x] < cur[x] && cur[x] < t[x];
}

int main () {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> h[i] >> r[i] >> t[i];
    }

    int lgst = *max_element(h, h + n);
    for (int i = 0; i < 1825 * lgst; ++i) {
        int cnt = 0;
        for (int j = 0; j < n; ++j) {
            cnt += hasSun(j);
            ++cur[j];
            cur[j] %= h[j];
        }
        if (cnt == 0) return cout << i << '\n', 0;
    }
    cout << "impossible\n";
    return 0;
}
