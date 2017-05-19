#include <iostream>
#include <cmath>
using namespace std;

bool isTriangular(long long n) {
        double test = (sqrt(8 * n + 1) - 1.0) / 2.0;
        return test == (long long)test;
}


bool isPentagonal(long long n) {
        double test = (sqrt(1 + 24 * n) + 1.0) / 6.0;
        return test == (long long)test;
}

bool isHexagonal(long long n) {
        double test = (sqrt(8 * n + 1) + 1.0) / 4.0;
        return test == (long long)test;
}


int main () {
        int i = 285;
        while(i++) {
                long long n = i * (i + 1.0) / 2.0;
                if(isPentagonal(n) && isHexagonal(n)) {
                        cout<<n<<endl;
                        return 0;
                }
        }
}
