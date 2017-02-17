#include <iostream>
#include <string>
#include <set>
using namespace std;

bool isPandigital(long long n) {
        int sum = 0;
        int prod = 1;
        while(n) {
                sum += n%10;
                prod *= n%10;
                n /= 10;
        }
        return sum == 45 && prod == 362880;
}

long long concat(long long x, long long y) {
        long long pow;
        while(y >= pow)
                pow *= 10;
        return x * pow + y;
}

int main() {
        set<int> nums;
        for (int a = 1; a < 9876; a++) {
                for (int b = 1; b < 9876; b++) {
                        int c = a * b;
                        if(c < 9877 && isPandigital(concat(concat(a, b), c)))
                                nums.insert(c);
                }
        }

        long long sum = 0;
        for(int i : nums)
                sum += i;
        
        cout<<sum<<endl;
}

