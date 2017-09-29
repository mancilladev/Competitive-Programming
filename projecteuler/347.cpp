#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int LIMIT = 10000000;
vector<int> isp(LIMIT/2+7, 1);
vector<int> primes;
vector<int> pqp;

void sieve () {
    for (int i = 2; i < (int)isp.size(); ++i) if (isp[i]) {
        primes.push_back(i);
        for (int j = i + i; j < (int)isp.size(); j += i) isp[j] = 0;
    }
}

int biggestDiscrete(int p, int q) {
    int lcm = p * q;
    int multlimit = LIMIT / lcm;
    int multiplier = 1;
    while (multiplier * p <= multlimit)
        multiplier *= p;
    int maxmult = multiplier;
    while (multiplier % p == 0) {
        multiplier /= p;
        while (multiplier * q <= multlimit)
            multiplier *= q;
        maxmult = max(multiplier, maxmult);
    }
    return maxmult * lcm;
}

ll sumBiggestSemiprimes () {
    ll res = 0;
    int END = sqrt(LIMIT);
    for (int i = 0; primes[i] < END; ++i) {
        for (int j = i + 1; j < (int)primes.size(); ++j) {
            if (primes[i] * primes[j] > LIMIT) break;
            res += biggestDiscrete(primes[i], primes[j]);
        }
    }
    return res;
}

int main () {
    sieve();
    cout << sumBiggestSemiprimes() << endl;
    return 0;
}
