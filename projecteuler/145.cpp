#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int allOddDigits(ll n) {
    while (n) {
        if (n%2 == 0)
            return 0;
        n /= 10;
    }
    return 1;
}

ll reverse(ll n) {
    ll a = 0;
    while (n)
        a = a*10 + n%10, n /= 10;
    return a;
}

int isReversible(ll n) {
    if (n%10 == 0)
        return 0;
    return allOddDigits(n + reverse(n));
}

int main () {
    ll N = 100'000'000;
    ll cnt = 0;
    for (ll i = 1; i < N; ++i)
        if (isReversible(i)) ++cnt;
    cout << cnt << endl;

    return 0;
}
