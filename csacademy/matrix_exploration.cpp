#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#ifdef LOCAL
#define deb(x) cout << #x << " = " << x << endl
#else
#define deb(x) 0
#endif
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()
#define sq(x) (x) * (x)
#define fi first
#define se second
#define FOR(i, a, b) for (int i(a); i < b; ++i)
#define REP(i, n) FOR (i, 0, n)
#define FORD(i, a, b) for (int i(a); i >= b; --i)

const int INF = 1e9 + 7, MN = 1007;
int N, M, K;
int dist[MN][MN];
const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};

int main (void) {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    while (cin >> N >> M >> K) {
        memset(dist, 0, sizeof dist);
        vector<string> mat(N);
        queue<pii> q;

        REP(i, N) cin >> mat[i];
        REP(i, K) {
            int y, x; cin >> y >> x;
            dist[--y][--x] = 1;
            q.push({y, x});
        }

        while (!q.empty()) {
            int x, y;
            tie(y, x) = q.front(); q.pop();

            REP(i, 4) {
                int yy = y + dy[i];
                int xx = x + dx[i];

                if (xx<0||xx>=M||yy<0||yy>=N) continue;
                if (mat[yy][xx] != '.' || dist[yy][xx] != 0) continue;

                dist[yy][xx] = dist[y][x]+1;
                q.push({yy, xx});
            }
        }

        ll ans = 0;
        REP(i, N) {
            REP(j, M) {
                if (dist[i][j] > 0)
                    ans += (dist[i][j] - 1);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
