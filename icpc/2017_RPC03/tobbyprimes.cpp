#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int LeastPower(int a, unsigned long long x) {
    unsigned long long b = a;

    while (x % b == 0) {
        b *= a;
        cout << a << ' ';
    }

    return b/a;
}

int main() {
    vector<int> isprime(100000000, 1);
    vector<int> primes;
    for (int i = 2; i < isprime.size(); ++i) if (isprime[i]) {
        primes.push_back(i);
        for (int j = i*i; j < isprime.size(); j+=i) isprime[j] = 0;
    }

    int t; cin >> t;

    while (t--) {
        unsigned long long n; cin >> n;

        for (auto p: primes) {
            if (n <= 1)
                break;
            n /= LeastPower(p, n);
        }

        if (n > 1)
            cout << n;

        cout << '\n';
    }

    return 0;
}

