#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> isp(100'000'003, 1);
int N = isp.size();

int divisorsMakePrime(ll n) {
    for (ll x = 1; x * x <= n; ++x) {
        if (n%x == 0 && !isp[x + n/x])
            return 0;
    }
    return 1;
}

int main(int argc, char const *argv[]) {
    isp[0] = 0; isp[1] = 0;
    for (ll i = 2; i * i < N; ++i) if (isp[i])
        for (ll j = i * i; j < N; j += i) isp[j] = 0;

    ll sum = 1;
    for (ll i = 2; i <= 100'000'000; i += 4) {
        if (divisorsMakePrime(i))
            sum += i;
    }
    cout << sum << endl;

    return 0;
}
