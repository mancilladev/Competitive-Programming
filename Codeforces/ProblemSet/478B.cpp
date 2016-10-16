#include <iostream>
using namespace std;


// Calculate [n * (n-1) * ... * (n-k+1)] / [k * (k-1) * ... * 1]
long long BinomialCoefficient(int n, int k) {
    cout<<"calculating"<<endl;
    long long res = 1;
    k = min(k, n-k);
    for(int i = 0; i != k; i++) {
        res *= (n-i);
        res /= (i+1);
    }
    cout<<"ok"<<endl;
    return res;
}


int main() {
    cout<<"lol"<<endl;
    cout<<BinomialCoefficient(8,2)<<endl;
    int N, M;
    while(cin>>N>>M) {
        cout<<N<<" "<<BinomialCoefficient(N-M-1,2)<<endl;
    }
}
