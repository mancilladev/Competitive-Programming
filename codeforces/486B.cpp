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

    int M, N;
    while (cin >> M >> N) {
        int arr[107][107], mat[107][107];
        forn(i, M) forn(j, N) cin >> arr[i][j];
        forn(i, M) forn(j, N) {
            bool f = true;
            forn(y, M) f &= arr[y][j];
            forn(x, N) f &= arr[i][x];
            mat[i][j] = f;
        }
        function<bool(void)> hasSolution = [&](void) {
            forn(i, M) forn(j, N) {
                bool f = false;
                forn(y, M) f |= mat[y][j];
                forn(x, N) f |= mat[i][x];
                if (arr[i][j] != f)
                    return false;
            }
            return true;
        };
        bool ok = hasSolution();
        cout << (ok ? "YES" : "NO") << '\n';
        if (ok) {
            forn(i, M) {
                forn(j, N) cout << mat[i][j] << ' ';
                cout << '\n';
            }
        }
    }
    return 0;
}
