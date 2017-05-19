#include <bits/stdc++.h>
using namespace std;
#define PB push_back
typedef long long ll;
typedef long double ld;
const ll INF = ll(1e18);
ll N, B, H, W;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    while (cin >> N >> B >> H >> W) {
        ll res = INF;
        ll price, beds;
        vector<bool> stayed(W, 0);
        for (int i = 0; i < H; ++i) {
            cin >> price;
            ll available = 0;
            for (int j = 0; j < W; ++j)
                cin >> beds, available = max(available, beds);
            if (price * N <= B && available >= N)
                res = min(res, price * N);
        }
        if (res == INF)
            cout << "stay home\n";
        else
            cout << res << '\n';
    }

    return 0;
}
