#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int a, b; cin >> a >> b;
    int tmp;

    if (a < b) {
        tmp = a;
        a = b;
        b = tmp;
    }

    long long secs = 0;
    while (min(a, b) > 0) {
        if (b < a) {
            tmp = a;
            a = b;
            b = tmp;
        }
        a += 1;
        b -= 2;
        if (min(a, b) >= 0)
            ++secs;
    }
    cout << secs << '\n';

    return 0;
}
