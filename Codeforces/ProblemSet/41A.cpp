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
    string s,t;
    while(cin>>s>>t) {
        bool rvrs = true;
        if(s.length() != t.length()) rvrs = false;
        else F(i,0,s.length()) if(s[i]!=t[t.length()-i-1]) {
            rvrs = false;
            break;
        }
        if(rvrs) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}
