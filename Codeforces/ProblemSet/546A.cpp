#include <iostream>
using namespace std;

int main() {
    int k,n,w;
    while(cin>>k>>n>>w) {
        int total = k*w*(w+1)/2;
        cout<<max(0,total-n)<<endl;
    }
}
