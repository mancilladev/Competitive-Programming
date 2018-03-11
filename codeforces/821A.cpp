#include <bits/stdc++.h>
using namespace std;

const int N = 57;
int n, a[N][N];

bool ok(int y, int x) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (a[y][x] == a[i][x] + a[y][j])
                return true;
        }
    }
    return false;
}

int main (void) {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (a[i][j] == 1) continue;
            if (!ok(i, j)) return cout << "No\n", 0;
        }
    }
    cout << "Yes\n";
    return 0;
}
