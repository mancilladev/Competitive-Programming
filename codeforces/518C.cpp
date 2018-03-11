#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
int n, m, k, a[N], b[N], pos[N];

int main (void) {
    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        pos[a[i]] = i;
    }
    vector<int> b(m);
    for (auto& x : b) cin >> x;

    long long res = 0;
    for (auto i : b) {
        res += (pos[i]/k) + 1;
        if (pos[i] == 0) continue;
        int last = a[pos[i] - 1];
        pos[i]--;
        pos[last]++;
        swap(a[pos[i]], a[pos[last]]);
    }
    cout << res << '\n';

    return 0;
}
