#include <iostream>
using namespace std;

int main () {
        long long sum = 0;
        for (int i = 1; i <= 1000; i++) {
                long long cur = 1;
                for (int j = 0; j < i; j++)
                        cur = (i*cur)%10000000000;
                sum = (sum+cur)%10000000000;
        }
        cout<<sum<<endl;
}
