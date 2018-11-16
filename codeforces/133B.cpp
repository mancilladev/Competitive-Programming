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

    string s;
    const ll MOD = 1e6 + 3;
    while (cin >> s) {
        ll ans = 0;
        for (auto c : s) {
            ans <<= 4;
            if (c == '>') ans += 8;
            if (c == '<') ans += 9;
            if (c == '+') ans += 10;
            if (c == '-') ans += 11;
            if (c == '.') ans += 12;
            if (c == ',') ans += 13;
            if (c == '[') ans += 14;
            if (c == ']') ans += 15;
            ans %= MOD;
        }
        cout << ans << '\n';
    }
    return 0;
}
