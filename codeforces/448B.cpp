#include <bits/stdc++.h>
#define mp make_pair
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

    string S, T;
    while (cin >> S >> T) {
        function<bool(string,string)> automaton = [&](string s,string t) {
            int cnt = 0;
            for (auto c : s) {
                if (c == t[cnt]) ++cnt;
                if (cnt == sz(t)) return true;
            }
            return false;
        };
        function<bool(void)> array = [&](void) {
            string s = S;
            string t = T;
            sort(all(s));
            sort(all(t));
            return (s == t);
        };
        function<bool(void)> both = [&](void) {
            string s = S;
            string t = T;
            sort(all(s));
            sort(all(t));
            return automaton(s, t);
        };
        if (array()) cout << "array\n";
        else if (automaton(S, T)) cout << "automaton\n";
        else if (both()) cout << "both\n";
        else cout << "need tree\n";
    }
    return 0;
}
