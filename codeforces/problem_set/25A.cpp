#include <iostream>
#include <vector>
using namespace std;
#define F(i,L,R) for(int i=L; i<R; i++)

int main() {
    int n;
    while(cin>>n) {
        vector<int> v(n);
        F(i,0,n) cin>>v[i];

        int even = 0;
        F(i,0,n) if(v[i]%2 == 0) even++;

        if(even > 1) {
            F(i,0,n) if(v[i]%2 != 0) {cout<<i+1<<endl; break;}
        }
        else {
            F(i,0,n) if(v[i]%2 == 0) {cout<<i+1<<endl; break;}
        }
    }
}
