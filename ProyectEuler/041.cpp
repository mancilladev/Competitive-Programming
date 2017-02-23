#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

#define MAX 987654325

bool isPandigital(long long n) {
		int digits = 0; int count = 0; int tmp;

        for (; n > 0; n /= 10, ++count)
        {
                tmp = digits;
                if (tmp == (digits |= 1 << (n - ((n / 10) * 10) - 1)))
                        return false;
        }

        return digits == (1 << count) - 1;
}

int main () {
        vector<bool> primes(MAX, 1);
        primes[0] = 0;
        primes[1] = 0;
        primes[2] = 1;
        for (int j = 4; j <= MAX; j+=2)
                primes[j] = false;
        for (int i = 3; i * i <= MAX; i+=2)
                if (primes[i])
                        for (int j = i * i; j <= MAX; j += i)
                                primes[j] = false;
        
        for (int i = MAX-1; i > 0; i--) {
                if (primes[i] && isPandigital(i)) {
                        cout<<i<<endl;
                        break;
                }
        }
}
