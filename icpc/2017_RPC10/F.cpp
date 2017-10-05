#include <bits/stdc++.h>
#define PB push_back
using namespace std;
typedef long long ll;
typedef long double ld;

int T, R, C;

int backtrack(vector<vector<int> > &M, int y, int x) {
    int cnt = 1;
    M[y][x] = 9;
    if (y > 0 && M[y-1][x] == 0) cnt += backtrack(M, y-1, x);
    if (y < R-1 && M[y+1][x] == 0) cnt += backtrack(M, y+1, x);
    if (x > 0 && M[y][x-1] == 0) cnt += backtrack(M, y, x-1);
    if (x < C-1 && M[y][x+1] == 0) cnt += backtrack(M, y, x+1);
    return cnt;
}

int main(void) {
    // freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(nullptr);
    cin >> T;
    while (T--) {
        cin >> R >> C;
        vector<vector<int> > M(R, vector<int>(C));
        int x = -1, y;
        for (int i = 0; i < R; ++i) for (int j = 0; j < C; ++j) {
            char c; cin >> c;
            M[i][j] = c - '0';
            if (x == -1) {
                if ((i == 0 || i == R-1) && M[i][j] == 0) x = i, y = j;
                if ((j == 0 || j == C-1) && M[i][j] == 0) x = i, y = j;
            }
        }
        cout << backtrack(M, y, x) << '\n';
    }
    return 0;
}
