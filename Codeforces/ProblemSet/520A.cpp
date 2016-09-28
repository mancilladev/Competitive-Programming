#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>

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
        string s;
        cin>>s;
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        set<char> alphabet;
        F(i,0,n) alphabet.insert(s[i]);
        if(alphabet.size() == 26) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}
