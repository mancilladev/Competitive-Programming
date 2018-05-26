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

    int N, K;
    const int MN = 507;
    while (cin >> N >> K) {
        int arr[MN][MN];
        --K;

        int it = 1;
        forn(i, N) {
            forn(j, K)
                arr[i][j] = it++;
        }
        int sum = 0;
        forn(i, N) {
            forn(j, N-K) {
                arr[i][K+j] = it++;
                if (j == 0)
                    sum += arr[i][K+j];
            }
        }

        cout << sum << '\n';
        forn(i, N) {
            forn(j, N)
                cout << arr[i][j] << ' ';
            cout << '\n';
        }
    }
    return 0;
}
