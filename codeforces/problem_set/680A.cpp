#include <bits/stdc++.h>
using namespace std;
#define PB push_back
typedef long long ll;
typedef long double ld;
const ll INF = ll(1e18);
vector<int> cnt(101, 0);

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int sum = 0, cur;
    for (int i = 0; i < 5; ++i) {
        cin >> cur;
        sum += cur;
        ++cnt[cur];
    }
    int res = sum;
    for (int i = 0; i < 101; ++i) {
        if (cnt[i] >= 2) {
            int possible = sum - min(cnt[i], 3) * i;
            res = min(res, possible);
        }
    }

    cout << res << endl;

    return 0;
}
