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
    string s;
    string keys = "HQ9";
    while(cin>>s) {
        bool prints = false;
        F(i,0,s.length()) if(spresent(keys,s[i])) { prints = true; break; }
        cout<<(prints?"YES":"NO")<<endl;
    }
}
