#include <iostream>
using namespace std;
#define F(i,L,R) for(int i=L; i<R; i++)

int main() {
    int n,m;
    while(cin>>n>>m) {
        bool r = false;
        F(i,0,n) {
            if(i%2==0) {
                F(j,0,m) cout<<"#";
                cout<<endl;
            }
            else {
                if(r) {
                    cout<<"#";
                    F(j,1,m) cout<<".";
                    cout<<endl;
                    r = false;
                }
                else {
                    F(j,1,m) cout<<".";
                    cout<<"#"<<endl;
                    r = true;
                }
            }
        }
    }
}
