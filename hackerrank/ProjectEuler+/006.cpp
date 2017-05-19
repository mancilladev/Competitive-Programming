#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int T; cin>>T;
    while(T--) {
        int N; cin>>N;

        unsigned long long a, b;
        
        a = N*(N+1)/2;
        a *= a;
        b = N*(N+1)*(2*N+1)/6;

        cout<<a-b<<endl;
    }
    return 0;
}
