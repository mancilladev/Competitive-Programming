#include <bits/stdc++.h>
using namespace std;

int main () {
    long long n; cin >> n;
    while (true) {
        cout << n << ' ';
        if (n == 1) break;
        n = (n&1 ? 3 * n + 1 : n / 2);
    }
    cout << endl;
    return 0;
}
