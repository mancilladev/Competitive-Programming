#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define PB push_back
#define MP make_pair
typedef long long ll;
const ll INF = ll(1e18);
ll N, x;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> N >> x;
    int failed = 0;
    while (N--) {
        char c;
        ll d;
        cin >> c >> d;
        if (c == '+')
            x += d;
        else if (d > x)
            ++failed;
        else
            x -= d;
    }

    cout << x << ' ' << failed << '\n';

    return 0;
}
