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
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, k;
    while (cin >> n >> k) {
        vector<pii> arr(n);
        forn(i, n) {
            int x; cin >> x;
            arr[i] = make_pair(x, i+1);
        }
        sort(all(arr), greater<pii>());
        cout << arr[k-1].fi << '\n';
        forn(i, k) cout << arr[i].se << ' ';
        cout << '\n';
    }
    return 0;
}
