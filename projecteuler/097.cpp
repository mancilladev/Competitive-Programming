#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll num_digits = (1e10);

int main () {
    ll res = 1;

    for (int i = 0; i < 7830457; ++i)
        res = (res * 2) % num_digits;

    res = (res * 28433) % num_digits;
    cout << res + 1 << endl;

    return 0;
}
