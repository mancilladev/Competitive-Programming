#include <bits/stdc++.h>
using namespace std;
#define PB push_back
typedef long long ll;
typedef long double ld;
const ll INF = ll(1e18);
ll T, W;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> T;
    while (T--) {
        cin >> W;
        int dist = -1;
        bool gap = 0;
        for (int i = 0; i < W; ++i) {
            int x, y;
            cin >> x >> y;
            if (dist == -1)
                dist = abs(x-y);
            else if (dist != abs(x-y))
                gap = 1;
        }
        cout << (gap ? "no" : "yes") << '\n';
        if (T)
            cout << '\n';
    }

    return 0;
}
