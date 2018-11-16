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

    int n, m, k;
    while (cin >> n >> m >> k) {
        int arr[1007][1007];
        for1(i, n) for1(j, m) cin >> arr[i][j];

        map<int,int> mr, mc;
        for1(i, n) mr[i] = i;
        for1(j, m) mc[j] = j;

        for1(i, k) {
            char s;
            int a, b;
            cin >> s >> a >> b;
            if (s == 'r') {
                int tmp = mr[a];
                mr[a] = mr[b];
                mr[b] = tmp;
            }
            if (s == 'c') {
                int tmp = mc[a];
                mc[a] = mc[b];
                mc[b] = tmp;
            }
            if (s == 'g') {
                int y = mr[a], x = mc[b];
                cout << arr[y][x] << '\n';
            }
        }
    }
    return 0;
}
