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

    int n;
    while (cin >> n) {
        vector<int> cnt(10);
        int x = n;
        while (x) {
            ++cnt[x%10];
            x /= 10;
        }

        vector<int> factors;
        for1(d, sqrt(n)) {
            if (n%d == 0) {
                factors.push_back(d);
                if (n/d != d) factors.push_back(n/d);
            }
        }
        function<bool(int)> shares = [&](int d) {
            while (d) {
                if (cnt[d%10]) return true;
                d /= 10;
            }
            return false;
        };
        int ans = 0;
        for (auto f : factors) {
            if (shares(f)) ++ans;
        }
        cout << ans << '\n';
    }
    return 0;
}
