#include <bits/stdc++.h>
#define PB push_back
using namespace std;
typedef long long ll;
int N = 100'000'000;
vector<int> isp(N+1, 1);
vector<int> primes;

ll s_prime(ll p, int e) {
    ll k = 0;
    while (e > p) {
        k += p;
        e -= p + 1;
        for (int t = k; (t /= p) % p == 0; ++t)
            --e;
    }
    return (k + max(0, e)) * p;
}

ll s(ll n) {
    if (isp[n])
        return n;

    ll best = 0;
    for (ll p : primes) {
        if (n % p != 0)
            continue;

        int e = 0;
        while (n % p == 0)
            ++e, n /= p;
        best = max(best, s_prime(p, e));

        // no further factorization possible
        if (n == 1)
            return best;
        if (isp[n])
            return max(best, n);
    }
    return best;
}

int main () {
    isp[0] = 0; isp[1] = 0;
    for (ll i = 2; i * i <= N; ++i) if (isp[i]) {
        primes.PB(i);
        for (ll j = i * i; j <= N; j += i) isp[j] = 0;
    }

    ll sum = 0;
    for (ll i = 2; i <= N; ++i)
        sum += s(i);
    cout << sum << endl;

    return 0;
}
