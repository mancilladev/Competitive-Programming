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
    string hi = "hello";
    while(cin>>s) {
        int cur = 0;
        int i = 0;
        while(cur < hi.length() && i < s.length()) {
            if(hi[cur] == s[i]) cur++;
            i++;
        }
        if(cur == hi.length()) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}
