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

    string a;
    string b;
    while (cin >> a >> b) {
        map<char,int> ca, cb;
        for(auto c : a) ++ca[c];
        for(auto c : b) ++cb[c];

        sort(all(b));
        b.erase(unique(all(b)), b.end());

        bool ok = true;
        int ans = 0;
        for(auto c : b) {
            if (!ca[c]) {
                ok = false;
                break;
            }
            ans += min(ca[c], cb[c]);
        }
        if (!ok) cout << -1 << '\n';
        else cout << ans << '\n';
    }
    return 0;
}
