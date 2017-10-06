#include <bits/stdc++.h>
#define PB push_back
using namespace std;
typedef long long ll;
typedef long double ld;

const int INF = 1e4 + 7, MAX = 107;
int T, N, M, a, b, w, link[MAX], size[MAX];

int find(int x) {
    while (link[x] != x) x = link[x];
    return x;
}

int same(int x, int y) {
    return find(x) == find(y);
}

void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (size[x] < size[y]) swap(x, y);
    size[x] += size[y];
    link[y] = x;
}

int main(void) {
    // freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(nullptr);
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        for (int i = 0; i < MAX; ++i) link[i] = i, size[i] = 1;

        cin >> N >> M;
        vector<tuple<int,int,int> > edg(M);
        for (int i = 0; i < M; ++i) {
            cin >> a >> b >> w;
            edg[i] = make_tuple(w, a, b);
        }

        int res = INF;
        sort(edg.begin(), edg.end(), greater<tuple<int,int,int> >());
        for (auto e : edg) {
            tie(w, a, b) = e;
            if (!same(a,b)) unite(a,b), res = min(res, w);
        }
        cout << "Case #" << t << ": " << res << '\n';
    }
    return 0;
}
