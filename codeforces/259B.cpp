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

    int arr[5][5];
    int N = 3;
    forn(i, N) forn(j, N) cin >> arr[i][j];

    function<bool(int)> solves = [&](int x) {
        arr[0][0] = x;
        int s = arr[0][0] + arr[0][1] + arr[0][2];
        arr[1][1] = s - arr[0][1] - arr[2][1];
        arr[2][2] = s - arr[0][2] - arr[1][2];
        forn(i, N) {
            int suma = 0;
            forn(j, N) suma += arr[i][j];
            if (suma != s) return false;
            suma = 0;
            forn(j, N) suma += arr[j][i];
            if (suma != s) return false;
        }
        return arr[0][0] + arr[1][1] + arr[2][2] == s;
    };

    const int MN = 1e5;
    for1(i, MN) {
        if (solves(i)) {
            forn(i, N) {
                forn(j, N) cout << arr[i][j] << ' ';
                cout << '\n';
            }
            break;
        }
    }
    return 0;
}
