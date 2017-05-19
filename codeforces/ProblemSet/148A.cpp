#include <iostream>
#include <vector>
#include <string>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
#define F(i,L,R) for(int i=L; i<R; i++)
#define FE(i,L,R) for(int i=L; i<=R; i++)
#define FFE(i,L,R) for (int i = L; i >= R; i--)
#define DBG(vari) cout<<#vari<<" = "<<(vari)<<endl;
#define spresent(str1,str2) (str1.find(str2) != string::npos)

int main() {
    int k,l,m,n;
    ll d;
    while(cin>>k>>l>>m>>n>>d) {
        ll cnt = 0;
        FE(i,1,d) if(i%k==0 || i%l==0 || i%m==0 || i%n==0) cnt++;
        cout<<cnt<<endl;
    }
}
