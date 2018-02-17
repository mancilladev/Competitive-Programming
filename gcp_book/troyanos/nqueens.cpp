#include <bits/stdc++.h>
using namespace std;

const int n = 12;
int cnt;
bool col[n*n], diag1[n*n], diag2[n*n];

void search(int y) {
    if (y == n) {
        ++cnt;
        return;
    }
    for (int x = 0; x < n; ++x) {
        if (col[x] || diag1[x+y] || diag2[x-y+n-1]) continue;
        col[x] = diag1[x+y] = diag2[x-y+n-1] = true;
        search(y+1);
        col[x] = diag1[x+y] = diag2[x-y+n-1] = false;
    }
}

int main(void) {
    search(0);
    cout << cnt << endl;
    return 0;
}

