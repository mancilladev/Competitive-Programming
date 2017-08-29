#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int main () {
    int n; cin >> n;
    vector< pair<int, int> > v(n);
    for (int i = 0; i < n; i++) {
        int l, r; cin >> l >> r;
        v[i] = {l, r};
    }

    sort(v.begin(), v.end(), [](auto &a, auto &b) {
            return a.second < b.second;
    });

    auto past = v[0];
    int cnt = 1;
    for (int i = 1; i < n; i++) {
        auto cur = v[i];
        if (cur.first > past.second)
            past = cur, ++cnt;
    }
    cout << cnt << '\n';

    return 0;
}
