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
        vector<int> arr, brr;
        ll sa = 0, sb = 0;
        int last = 0;
        forn(i, n) {
            int x; cin >> x;
            if (x < 0) brr.push_back(abs(x)), sb += abs(x);
            else arr.push_back(abs(x)), sa += abs(x);
            last = (x < 0 ? -1 : 1);
        }
        function<int(vector<int>,vector<int>)> lexlar = [&](vector<int> v1, vector<int> v2) {
            forn(i, min(sz(v1), sz(v2))) {
                if (v1[i] != v2[i])
                    return (v1[i] > v2[i]) - (v1[i] < v2[i]);
            }
            return (sz(v1) > sz(v2)) - (sz(v1) < sz(v2));
        };
        int lx = lexlar(arr, brr);
        int res = last;
        if (sa == sb) {
            if (lx != 0) res = lx;
        } else {
            res = (sa > sb ? 1 : -1);
        }
        cout << (res == 1 ? "first" : "second") << '\n';
    }
    return 0;
}
