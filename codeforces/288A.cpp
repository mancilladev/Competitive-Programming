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
    while (cin >> n >> k) {
        function<string(void)> solves = [&](void) {
            if (k == 1) return string(n == 1 ? "a" : "-1");
            if (k > n) return string("-1");
            string res;
            forn(i, n-(k-2)) {
                if (res.empty() || res.back() == 'b')
                    res += 'a';
                else
                    res += 'b';
            }
            forn(i, k-2) {
                res += ('a' + i + 2);
            }
            return res;
        };
        string ans = solves();
        cout << ans << '\n';
    }
    return 0;
}
