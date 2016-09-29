#include <iostream>
#include <vector>
using namespace std;
#define F(i,L,R) for(int i=L; i<R; i++)

int main() {
    vector<int> v(46);
    F(i,1,46) v[i] = v[i-1]+i*(i+1)/2;

    int n;
    while(cin>>n) {
        F(i,0,v.size()) if(v[i] > n) { cout<<i-1<<endl; break; }
    }
}
