#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
typedef long long ll;
using namespace std;

int LeastPower(ll a, ll x) {
    // Least power (a^k) that does not divide x
    int b = a, k = 0;
    while (x % a == 0)
        a *= b, ++k;
    return k+1;
}

int main() {
    vector<int> isprime(10000, 1), primes;
    for (int i = 2; i < isprime.size(); ++i) if (isprime[i]) {
        primes.push_back(i);
        for (int j = i*i; j < isprime.size(); j += i) isprime[j] = 0;
    }

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    
    while (t--) {
        ll cur; cin >> cur;
        ll n = cur;
        ll sum = 1;

        int i = 0;
        for (auto prime: primes) {
            if (n <= 1) break;
            // Sum factors 120 = (1+2+2^2+2^3)*(1+3)*(1+5) = 15*4*6 = 360
            // p^0 + p^1 + ... + p^(h-1) = (p^h-1) / (p-1)

            int h = LeastPower(prime, n);
            ll ph = pow(prime, h);
            ll summationpi = (ph - 1) / (prime - 1);
            sum *= summationpi;
            n /= ph/prime;
        }

        sum -= cur;

        if (sum > cur) cout << "abundant\n";
        else if (sum < cur) cout << "deficient\n";
        else cout << "perfect\n";
    }

    return 0;
}
