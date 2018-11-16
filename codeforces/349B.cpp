#include <bits/stdc++.h>
#define fi first
#define se second
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()
#define deb(x) cout << #x << " = " << x << endl
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define fore(i, l, r) for (int i = (int)(l); i <= (int)(r); ++i)
#define ford(i, n) for (int i = (int)(n) -1; i >= 0; --i)

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int main (void) {
    ios::sync_with_stdio(false), cin.tie(0);
    cout.precision(10), cout << fixed;

    int v;
    const int inf = 1e9 + 7;
    while (cin >> v) {
        int best = 0;
        vector<int> cost(10, inf);
        for1(i, 9) {
            cin >> cost[i];
            if (cost[i] <= cost[best]) {
                best = i;
            }
        }
        int len = v/cost[best];
        if (len == 0) {
            cout << -1 << '\n';
            continue;
        }

        v -= len * cost[best];
        vector<int> res(len);
        forn(i, len) {
            int d = best, r = 0;
            fore(x, best+1, 9) {
                if (v >= cost[x] - cost[best]) {
                    r = cost[x] - cost[best];
                    d = x;
                }
            }
            v -= r;
            res[i] = d;
        }

        for(auto it : res) cout << it;
        cout << '\n';
    }
    return 0;
}
