#include <bits/stdc++.h>
using namespace std;

int main (void) {
    int a, b; cin >> a >> b;
    if (a == 0 && b == 0) return cout << "Not a moose\n", 0;
    string s = (a == b ? "Even" : "Odd");
    cout << s << ' ' << max(a, b) * 2 << '\n';
    return 0;
}
