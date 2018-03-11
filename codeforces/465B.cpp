#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 7;
int n;
bool a[N];

int main (void) {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    int res = 0;
    bool flag = 0;
    for (int i = 0; i < n; ++i) {
        if (!flag && a[i]) ++res;

        if (a[i]) ++res, flag = 1;
        else flag = 0;
    }
    cout << max(res-1, 0) << '\n';
    return 0;
}
