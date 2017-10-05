#include <bits/stdc++.h>
#define PB push_back
using namespace std;
typedef long long ll;
typedef long double ld;

int INF = 1e4 + 7;
int T, N, M, u, v, c;
int main(void) {
    // freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(nullptr);
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cin >> N >> M; ++N;
        vector<vector<int> > matrix(N, vector<int>(N, INF));
        for (int i = 0; i < M; ++i) {
            cin >> u >> v >> c;
            matrix[u][v] = min(matrix[u][v], c);
            matrix[v][u] = min(matrix[v][u], c);
        }
        int sum = 0;
        for (int i = 0; i < N; ++i)
            for (int j = i+1; j < N; ++j)
                if (matrix[i][j] != INF) sum += matrix[i][j];
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                cout << (matrix[i][j] == INF ? 0 : matrix[i][j]) << ' ';
            }
            cout << '\n';
        }
        cout << "Case #" << t << ": " << sum << '\n';
    }
    return 0;
}
