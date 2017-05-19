#include <iostream>
#include <vector>
#include <cmath>
#include <set>
#define MAX 1000000000000
typedef long long ll;
using namespace std;
set<ll> perfect_nums = {6, 28, 496, 8128, 33550336, 8589869056};

bool divisibleByPerfect(ll n) {
    for (ll p: perfect_nums)
        if (n % p == 0)
            return true;
    return (n%20 == 0);
}

ll LeastPower(ll a, ll x) {
    ll b = a;
    while (x % b == 0)
        b *= a;
    return b;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<int> isprime(1000000, 1);
    set<ll> primes;
    for (int i = 2; i < isprime.size(); ++i) if (isprime[i]) {
        primes.insert(i);
        for (int j = i*i; j < isprime.size(); j += i) isprime[j] = 0;
    }

    int t; cin >> t;
    
    while (t--) {
        ll cur; cin >> cur;
        ll n = cur;

        if (perfect_nums.find(cur) != perfect_nums.end()) {
            cout << "perfect\n";
            continue;
        }
        if (divisibleByPerfect(n)) {
            cout << "abundant\n";
            continue;
        }
        if (primes.find(n) != primes.end()) {
            cout << "deficient\n";
            continue;
        }

        ll sum = 1;
        for (auto prime: primes) {
            if (n <= 1) break;
            // Sum factors 120 = (1+2+2^2+2^3)*(1+3)*(1+5) = 15*4*6 = 360
            // p^0 + p^1 + ... + p^(h-1) = (p^h-1) / (p-1)

            ll ph = LeastPower(prime, n);
            sum *= (ph - 1) / (prime - 1);
            n /= ph/prime;
        }

        sum -= cur;

        if (sum > cur) cout << "abundant\n";
        else cout << "deficient\n";
    }

    return 0;
}
