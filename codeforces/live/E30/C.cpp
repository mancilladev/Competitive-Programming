#include <bits/stdc++.h>
using namespace std;
#define error(x) cerr << #x << " = " << x << endl
#define mt make_tuple
#define eb emplace_back
#define pb push_back
typedef long long ll;
typedef long double ld;

int N, M, K;
int main(void) {
    // freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(nullptr);
    cin >> N >> M >> K;
    vector<vector<int>> matrix(M, vector<int>(N));
    for (int x = 0; x < N; ++x)
        for (int y = 0; y < M; ++y)
            cin >> matrix[y][x];

    int res = 0, replacements = 0;
    for (int y = 0; y < M; ++y) {
        int past = 0, best = 0, del = 0;
        for (int x = 0; x < N; ++x) if (matrix[y][x]) {
            int cursum = 0;
            for (int k = 0; k < min(K, N-x); ++k) cursum += matrix[y][x+k];
            if (cursum > best) del = past, best = cursum;
            ++past;
        }
        res += best;
        replacements += del;
    }
    cout << res << ' ' << replacements << endl;
    return 0;
}
