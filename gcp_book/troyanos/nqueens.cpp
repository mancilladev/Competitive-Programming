#include <bits/stdc++.h>
using namespace std;

const int n = 25;
int cnt;
bool col[n*n], diag1[n*n], diag2[n*n];
unordered_map<int, int> q;

void printBoard() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << (q[i] == j ? 'Q' : '_') << ' ';
        }
        cout << endl;
    }
}

bool search(int y) {
    if (y == n) {
        ++cnt;
        printBoard();
        return true;
    }
    for (int x = 0; x < n; ++x) {
        if (col[x] || diag1[x+y] || diag2[x-y+n-1]) continue;
        col[x] = diag1[x+y] = diag2[x-y+n-1] = true;
        q[y] = x;
        if (search(y+1)) return true;
        col[x] = diag1[x+y] = diag2[x-y+n-1] = false;
    }
    return false;
}

int main(void) {
    search(0);
    cout << cnt << endl;
    return 0;
}

