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
    int n;
    while(cin>>n) {
        int temp;
        vi ans(3,0);
        F(i,0,n) {
            cin>>temp;
            ans[0]+=temp;
            cin>>temp;
            ans[1]+=temp;
            cin>>temp;
            ans[2]+=temp;
        }
        if(ans[0]==0 && ans[1]==0 && ans[2]==0) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}
