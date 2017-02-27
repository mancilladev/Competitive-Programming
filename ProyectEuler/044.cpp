#include <iostream>
#include <cmath>
#include <climits>
#define MAX 10000
using namespace std;

bool isPentagonal(long long n) {
        double penTest = (sqrt(1 + 24 * n) + 1.0) / 6.0;
        return penTest == (long long)penTest;
}

long long pentagonal(int n) {
        return n*(3*n-1)/2;
}

int main () {
        int i = 0;
        while(true) {
                i++;
                long long n = pentagonal(i);
                for (int j = i-1; j > 0; j--) {
                        long long m = pentagonal(j);
                        if(isPentagonal(n-m) && isPentagonal(n+m)) {
                                cout<<n-m<<endl;
                                return 0;
                        }
                }
        }
}
