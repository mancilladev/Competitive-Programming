#include <iostream>
#include <string>
using namespace std;
#define F(i,L,R) for(int i=L; i<R; i++)

int main() {
    string a, b, c;
    while(cin>>a>>b>>c) {
        if(c.size() == a.size() + b.size()) {
            F(i,0,a.size()) {
                F(j,0,c.size()) if(c[j] == a[i]) { c.erase(c.begin()+j); break; }
            }
            F(i,0,b.size()) {
                F(j,0,c.size()) if(c[j] == b[i]) { c.erase(c.begin()+j); break; }
            }
        }
        if(c.size() == 0) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}
