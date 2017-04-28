#include <bits/stdc++.h>
using namespace std;
#define PB push_back
typedef long long ll;
typedef long double ld;
const ll INF = ll(1e18);
int N, grid[101][101] {{0}};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> N;
    ll res = 0;
    for (int i = 0; i < N; ++i) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for (int y = y1; y <= y2; ++y)
            for (int x = x1; x <= x2; ++x)
                ++res;
    }
    cout << res << '\n';

    return 0;
}
