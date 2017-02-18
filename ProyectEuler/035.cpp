#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>
using namespace std;

vector<int> primes(1000001, 1);


int intSize(int n) {
        int len = 1;
        while(n /= 10)
                len++;
        return len;
}

int rotate(int n) {
        // 197 -> 971
        int k = pow(10, intSize(n)-1);
        return n%k*10 + n/k;
}

bool isCircular(int n) {
        int nlen = intSize(n);
        for (int i = 0; i < nlen; i++) {
                n = rotate(n);
                if(!primes[n] || intSize(n) != nlen)
                        return false;
        }
        return true;
}


int main () {
        primes[0] = 0;
        primes[1] = 0;
        for (int i = 2; i < primes.size(); i++)
                if(primes[i])
                        for(int j = i*i; j < primes.size(); j+=i)
                                primes[j] = 0;

        int count = 0;
        for (int i = 2; i < primes.size(); i++) {
                if(primes[i] && isCircular(i)) {
                        count++;
                }
        }
        cout<<count<<endl;
}
