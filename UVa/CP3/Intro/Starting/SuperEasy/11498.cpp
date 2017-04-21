#include <bits/stdc++.h>
using namespace std;
#define PB push_back
typedef long long ll;
typedef long double ld;
const ll INF = ll(1e18);
ll K, X, Y, dx, dy;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    while (cin >> K, K != 0) {
        cin >> dx >> dy;
        while (K--) {
            cin >> X >> Y;
            X -= dx;
            Y -= dy;
            if (X * Y == 0) {
                cout << "divisa\n";
                continue;
            }
            if (Y > 0) cout << "N";
            else cout << "S";
            if (X > 0) cout << "E";
            else cout << "O";
            cout << '\n';
        }
    }

    return 0;
}
