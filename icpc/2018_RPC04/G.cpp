#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, n) FOR(i, 0, n)
#define FORD(i, a, b) for(int i = a; i >= b; --i)

const int N = 107;
int R, C, T, g;
bool M[N][N], visited[N][N];

int dfs(int y, int x) {
    if (!M[y][x] || visited[y][x])
        return 0;
    int res = 1;
    visited[y][x] = true;
    FOR(i, -1, 2) {
        FOR(j, -1, 2) {
            if (i == 0 || j == 0)
                res += dfs(y+i, x+j);
        }
    }
    return res;
}

int main (void) {
    cin >> T >> g;
    cin >> R >> C;

    FOR(i, 1, R+1) FOR(j, 1, C+1) {
        int x; cin >> x;
        M[i][j] = (x == 1 ? true : false);
    }

    int components = 0, benefit = 0;
    FOR(i, 1, R+1) FOR(j, 1, C+1) {
        if (visited[i][j])
            continue;
        int size = dfs(i, j);
        if (size >= T) {
            ++components;
            benefit += (size - T) * g;
        }
    }
    cout << components << ' ' << benefit << endl;
    return 0;
}
