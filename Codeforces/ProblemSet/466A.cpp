#include <iostream>
using namespace std;

int main() {
    int n,m,a,b;
    while(cin>>n>>m>>a>>b) {
        if(m*a <= b) cout<<n*a<<endl;
        else cout<<n/m*b + min(b, n%m*a)<<endl;
    }
}
