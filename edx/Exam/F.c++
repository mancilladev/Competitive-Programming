#ifdef JUDGE
#include <fstream>
std::ifstream cin("input.txt");
std::ofstream cout("output.txt");
#else
#include <iostream>
#endif
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 1001;
int N, M;
int grid[MAX][MAX];
int largest[MAX][MAX];

int recorrer(int y, int x) {
    if (largest[y][x])
        return largest[y][x];
    largest[y][x] = 1;

    if (y < N-1 && grid[y+1][x]+1 == grid[y][x])
        largest[y][x] = max(largest[y][x], 1 + recorrer(y+1, x));

    if (y > 0 && grid[y-1][x] + 1 == grid[y][x])
        largest[y][x] = max(largest[y][x], 1 + recorrer(y-1, x));

    if (x < M-1 && grid[y][x+1] + 1 == grid[y][x])
        largest[y][x] = max(largest[y][x], 1 + recorrer(y, x+1));

    if (x > 0 && grid[y][x-1] + 1 == grid[y][x])
        largest[y][x] = max(largest[y][x], 1 + recorrer(y, x-1));

    return largest[y][x];
}

int largestPath() {
    int res = 1;
    for (int y = 0; y < N; ++y)
        for (int x = 0; x < M; ++x)
            res = max(res, recorrer(y, x));
    return res;
}

int main() {
    cin >> N >> M;
    for (int y = 0; y < N; ++y)
        for (int x = 0; x < M; ++x)
            largest[y][x] = 0, cin >> grid[y][x];

    cout << largestPath() << endl;

    return 0;
}
