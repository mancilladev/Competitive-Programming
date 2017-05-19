#include <iostream>
#include <string>
#include <cmath>
using namespace std;
#define F(i,L,R) for(int i=L; i<R; i++)


int main() {
    int n,t;
    while(cin>>n>>t) {
        if(t==10) {
            if(n==1) cout<<-1<<endl;
            else { F(i,1,n) cout<<1; cout<<0<<endl; }
        }
        else {
            F(i,0,n) cout<<t;
            cout<<endl;
        }
    }
}
