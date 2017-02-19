#include <iostream>
#include <vector>
#include <cmath>
#include <cassert>
using namespace std;

#define MAX 1000000

vector<long long> primes(MAX, 1);

long long len(long long n) {
        long long x = 1;
        while(n/=10)
                x++;
        return x;
}

long long remLeft(long long n, long long k) {
        return n%((long long)pow(10, k+1));
}


long long remRight(long long n, long long k) {
        return n/(pow(10, k+1));
}

bool applies(long long n) {
        for (long long i = 0; i < len(n)-1; i++)
                if(!primes[remLeft(n, i)])
                        return false;
        for (long long i = 0; i < len(n)-1; i++)
                if(!primes[remRight(n, i)])
                        return false;
        return true;
}

int main() {
        // Get primes
        primes[0] = 0;
        primes[1] = 0;
        for (long long i = 2; i < MAX; i++)
                if(primes[i])
                        for (long long j = i*i; j < MAX; j+=i)
                                primes[j] = 0;

        // Tests
        assert(len(1000) == 4);
        assert(len(1) == 1);
        assert(remLeft(1234, 0) == 4);
        assert(remLeft(1234, 1) == 34);
        assert(remLeft(1234, 2) == 234);
        assert(remRight(1234, 0) == 123);
        assert(remRight(1234, 1) == 12);
        assert(remRight(1234, 2) == 1);
        
        // Program
        long long sum = 0;
        for (long long i = 10; i < MAX; i++) {
                if(primes[i] && applies(i))
                        sum+=i;
        }
        cout<<sum<<endl;
}
