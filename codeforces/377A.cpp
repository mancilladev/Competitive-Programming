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

    int n, m, k;
    const int dy[4] = {0,0,-1,1};
    const int dx[4] = {-1,1,0,0};
    while (cin >> n >> m >> k) {
        vector<string> maze(n);
        forn(i, n) cin >> maze[i];

        int vis[507][507];
        memset(vis, 0, sizeof vis);
        function<void(int,int)> dfs = [&](int y, int x) {
            vis[y][x] = true;
            forn(i, 4) {
                int yy = y + dy[i];
                int xx = x + dx[i];
                if (yy<0||yy>=n||xx<0||xx>=m) continue;
                if (vis[yy][xx] || maze[yy][xx] != '.') continue;
                dfs(yy, xx);
            }
            if (k) {
                maze[y][x] = 'X';
                --k;
            }
        };

        bool start = false;
        forn(y, n) {
            forn(x, m) if (maze[y][x] == '.') {
                start = true;
                dfs(y, x);
                break;
            }
            if (start) break;
        }

        forn(y, n) cout << maze[y] << '\n';
    }
    return 0;
}
