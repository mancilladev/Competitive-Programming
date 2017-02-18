#include <iostream>
using namespace std;

long long factorial(int n) {
        return (n == 0) ? 1 : n * factorial(n-1);
}

long long sumFactorialDigits(int n) {
        long long sum = 0;
        while(n) {
                sum += factorial(n%10);
                n /= 10;
        }
        return sum;
}

int main() {
        long long sum = 0;
        for(int i = 10; i < 1000000; i++)
                if(sumFactorialDigits(i) == i)
                        sum += i;
        cout<<sum<<endl;
}
