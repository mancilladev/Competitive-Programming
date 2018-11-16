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
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n, k;
    const int INF = 1e9;
    while (cin >> n >> k) {
        int m = n/2;
        if (m > k || (m == 0 && k != 0)) {
            cout << -1 << '\n';
            continue;
        }
        int last = 1;
        ll g = 0;
        for1(i, m) {
            if (i == 1) {
                int x = k - (m - i);
                cout << x << ' ' << x * 2 << ' ';
                g += x;
                last = x * 2;
            } else {
                ++g;
                cout << (++last) << ' ';
                cout << (++last) << ' ';
            }
        }
        if (n&1) cout << INF;
        cout << '\n';
        assert(g == k);
    }
    return 0;
}
