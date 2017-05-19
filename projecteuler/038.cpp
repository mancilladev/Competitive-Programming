#include <iostream>
#include <cassert>
#include <cmath>
using namespace std;

int len(long long n) {
        int cnt = 1;
        while(n /= 10)
                cnt++;
        return cnt;
}

long long append(int h, int t) {
        return h * pow(10, len(t)) + t;
}

bool isPandigital(long long n) {
        if (len(n) != 9)
                return false;
        int s = 0;
        int ss = 0;
        while(n) {
                int k = n%10;
                s += k;
                ss += k * k;
                n = n/10;
        }
        return s == 45 && ss == 285;
}

long long pandigitalSum(int n) {
        int i = 1;
        long long x = n;
        while(len(x) < 9)
                x = append(x, n * ++i);
        return isPandigital(x) ? x : 0;
}

int main () {
        // Tests
        assert(len(123) == 3);
        assert(len(2120050812906810) != 9);
        assert(append(123, 987) == 123987);
        assert(isPandigital(192384576));
        assert(!isPandigital(192384738));
        assert(!isPandigital(2120050812906810));

        // Program
        long long largest = 0;

        for (int i = 1; i < 10000; i++)
                largest = max(largest, pandigitalSum(i));

        cout<<largest<<endl;
}
