#include <iostream>
#include <vector>
#include <set>
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
    while(cin>>s) {
        set<char> chars(s.begin(), s.end());
        if((chars.size()+1)%2) cout<<"CHAT WITH HER!"<<endl;
        else cout<<"IGNORE HIM!"<<endl;
    }
}
