#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <utility>
using namespace std;
#define F first
#define S second
#define PB push_back
#define MP make_pair
typedef long long ll;
const ll INF = ll(1e18);

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int N, L, R; cin >> N >> L >> R;
    vector<int> a(N);
    vector< pair<int, int> > p(N);
    for (int i = 0; i < N; ++i)
        cin >> a[i];
    for (int i = 0; i < N; ++i)
        cin >> p[i].F, p[i].S = i;

    sort(p.begin(), p.end(), [](auto &x, auto &y) { return x.F < y.F; });

    bool ok = true;
    for (int i = 0; i < N; ++i) {
        int bot, top, x;
        bot = L - a[p[i].S];
        top = R - a[p[i].S];
        x = bot;
        if (i != 0)
            x = max(x, p[i-1].F + 1);
        if (x > top) {
            ok = false;
            break;
        }
        p[i].F = x;
    }

    sort(p.begin(), p.end(), [](auto &x, auto &y) { return x.S < y.S; });

    if (!ok) cout << "-1";
    else for (int i = 0; i < N; ++i) {
        cout << p[i].F + a[i] << ' ';
    }
    cout << '\n';

    return 0;
}
