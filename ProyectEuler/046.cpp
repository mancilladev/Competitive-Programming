#include <iostream>
#include <vector>
#define MAX 10000
using namespace std;

vector<bool> primes(MAX+1, 1);

bool sumPrimeSquare(long long n) {
        long long b = 1;
        while (n > 2*b*b && !primes[n-2*b*b])
                b++;
        return n > 2*b*b && primes[n-2*b*b];
}

int main () {
        primes[0] = 0;
        primes[1] = 0;
        for (long long i = 2; i < MAX; i++)
                if (primes[i])
                        for (long long j = i*i; j < MAX; j += i)
                                primes[j] = 0;
        long long i = 9;
        while (i < MAX) {
                if (!primes[i] && !sumPrimeSquare(i)) {
                        cout<<i<<endl;
                        return 0;
                }
                i += 2;
        }
}
