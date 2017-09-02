#include <bits/stdc++.h>
#define PB push_back
using namespace std;
typedef long long ll;
typedef long double ld;
const ll INF = ll(1e18);

const int N = (1e5 + 7);
int n, w, h;
int g[N], p[N], t[N];

vector<int> s[N<<1];
int ans_x[N], ans_y[N];

int main(void) {
    // freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(nullptr);
    cin >> n >> w >> h;
    for (int i = 0; i < n; ++i) {
        cin >> g[i] >> p[i] >> t[i];
        s[p[i] - t[i] + N].PB(i);
    }

    vector<int> xs, ys;
    for (int i = 0; i < N<<1; ++i) if (!s[i].empty()) {
        for (int u : s[i])
            g[u] == 1 ? xs.PB(p[u]) : ys.PB(p[u]);
        sort(xs.begin(), xs.end());
        sort(ys.begin(), ys.end());
        sort(s[i].begin(), s[i].end(), [] (int u, int v) {
                if (g[u] != g[v]) return (g[u] == 2);
                return (g[u] == 2 ? p[u] > p[v] : p[u] < p[v]);
        });
        for (int j = 0; j < (int) xs.size(); ++j) {
            ans_x[s[i][j]] = xs[j];
            ans_y[s[i][j]] = h;
        }
        for (int j = 0; j < (int) ys.size(); ++j) {
            ans_x[s[i][j + xs.size()]] = w;
            ans_y[s[i][j + xs.size()]] = ys[ys.size() - j - 1];
        }
        xs.clear();
        ys.clear();
    }

    for (int i = 0; i < n; ++i) printf("%d %d\n", ans_x[i], ans_y[i]);

    return 0;
}

