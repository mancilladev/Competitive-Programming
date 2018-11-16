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

int n, p;
string a, b;

bool find (int cur, bool greater) {
    if (cur >= sz(a)) return greater;

    fore(c, 'a', 'a' + p - 1) {
        if (cur > 0 && c == b[cur-1]) continue;
        if (cur > 1 && c == b[cur-2]) continue;
        if (!greater && c < a[cur]) continue;

        b[cur] = c;
        if (find(cur + 1, greater || c > a[cur])) return true;
        b[cur] = ' ';
    }
    return false;
}

int main (void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;

    while (cin >> n >> p >> a) {
        bool ok = false;
        ford(keep, n) {
            b = a.substr(0, keep);
            while (sz(b) < sz(a)) b += ' ';
            if (find(keep, false)) {
                cout << b << '\n';
                ok = true;
                break;
            }
        }
        if (!ok) cout << "NO\n";
    }
    return 0;
}
