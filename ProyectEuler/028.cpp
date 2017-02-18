#include<iostream>
using namespace std;

int main () {
        int N = 1001;
        long long sum = 1;
        for(int x = 1; x <= N/2; x++) {
                sum += 4*x*x + 2*x + 1;
                sum += 4*x*x - 2*x + 1;
                sum += 4*x*x + 4*x + 1;
                sum += 4*x*x + 1;
        } 
        cout<<sum<<endl;
}
