#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 7;
int a, b;

int main (void) {
    cin >> a >> b;
    for (int i = 1; i <= INF; ++i) {
        if (i&1) a -= i;
        else b -= i;

        if (a < 0) return cout << "Vladik\n", 0;
        if (b < 0) return cout << "Valera\n", 0;
    }
    return 0;
}
