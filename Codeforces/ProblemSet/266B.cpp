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
    int n,t;
    while(cin>>n>>t) {
        string s;
        cin>>s;
        F(i,0,t) FFE(j,s.length(),1) if(s[j]=='G' && s[j-1] == 'B') { swap(s[j],s[j-1]); j--; }
        cout<<s<<endl;
    }
}
