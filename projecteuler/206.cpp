#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool solves (ll n) {
    string s = to_string(n);
    for (int i = 0; i <= 8; ++i) {
        if ((s[i * 2] - '0') != i + 1)
            return false;
    }
    return true;
}

int main(int argc, char const *argv[]) {
    ll x = 138902663;
    while (!solves(x * x))
        --x;
    printf("%llu\n", x);
    return 0;
}
