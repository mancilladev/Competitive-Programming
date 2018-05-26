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

    int N;
    while (cin >> N) {
        vector<pii> arr(N);
        forn(i, N) cin >> arr[i].fi >> arr[i].se;
        map<int,int> home;
        forn(i, N) home[arr[i].fi]++;
        forn(i, N) {
            int x = home[arr[i].se] + (N-1);
            cout << x << ' ' << (N-1)*2-x << '\n';
        }
    }
    return 0;
}
