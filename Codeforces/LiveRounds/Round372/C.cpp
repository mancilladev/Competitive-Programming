#include <iostream>
#include <vector>
#include <string>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
#define F(i,L,R) for(int i=L; i<R; i++)
#define FFE(i,L,R) for (int i = L; i >= R; i--)
#define DBG(vari) cout<<#vari<<" = "<<(vari)<<endl;
#define spresent(str1,str2) (str1.find(str2) != string::npos)

int main() {
    ll n;
    while(cin>>n) {
        for(ll i=1; i<=n; i++)
            if(i==1) cout<<2<<endl;
            else cout<<i*(i+1)*(i+1)-(i-1)<<endl;;
    }
}
