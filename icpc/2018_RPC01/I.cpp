#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main(void) {
    int n; cin >> n;
    vector<int> v(n);
    for (auto& x : v) cin >> x;
    int h; cin >> h;

    int best[2] {-1, INF};
    for (auto x : v) if (h%x < best[1]) {
        best[0] = x;
        best[1] = h%x;
    }
    cout << best[0] << '\n';
    return 0;
}
