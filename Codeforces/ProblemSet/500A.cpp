#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
#define F(i,L,R) for(int i=L; i<R; i++)
#define FFE(i,L,R) for (int i = L; i >= R; i--)
#define DBG(vari) cout<<#vari<<" = "<<(vari)<<endl;
#define spresent(str1,str2) (str1.find(str2) != string::npos)

int main() {
    int n,t;
    while(cin>>n>>t) {
        vi v(n);
        F(i,0,n-1) cin>>v[i];

        bool arrives = false;
        F(i,0,n) {
            if(i+1==t) {
                arrives = true;
                break;
            }
            if(i+1==n) break;
            i+=v[i]-1;
        }

        if(arrives) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}
