#include <bits/stdc++.h>
#define PB push_back
using namespace std;
typedef long long ll;
typedef long double ld;

int n, a[1003][7], AB[7], BC[7];

int main(void) {
    // freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < 5; ++j)
            cin >> a[i][j];
    vector<int> ans;
    for (int i = 0; i < n; ++i) {
        int good = 1;
        for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) if (i != j && j != k && i != k) {
            for (int z = 0; z < 5; ++z) AB[z] = a[j][z] - a[i][z];
            for (int z = 0; z < 5; ++z) BC[z] = a[k][z] - a[i][z];
            ld val = 0;
            for (int z = 0; z < 5; ++z) val += AB[z] * BC[z];
            if (val > 0) good = 0;
            if (!good) j = n, k = n;
        }
        if (good) ans.PB(i);
    }
    cout << ans.size() << '\n';
    for (auto x : ans)
        cout << x + 1 << '\n';
    return 0;
}
