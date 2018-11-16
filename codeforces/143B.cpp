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

    string s;
    while (cin >> s) {
        vector<char> st;
        string res;
        int d = 0;
        int p = sz(s);
        forn(i, sz(s)) if (s[i] == '.') p = i+1;
        if (s[0] == '-') res += ")";
        ford(i, p) {
            char c = s[i];
            if (i == p-1) {
                res += (i+2 < sz(s) ? s[i+2] : '0');
                res += (i+1 < sz(s) ? s[i+1] : '0');
                res += '.';
                if (c == '.') continue;
            }
            if (i == 0 && c == '-') {
                res += "$(";
                break;
            }
            if (d++ == 3) {
                res += ',';
                d = 1;
            }
            res += c;
            if (i == 0) res += '$';
        }
        reverse(all(res));
        cout << res << '\n';
    }
    return 0;
}
