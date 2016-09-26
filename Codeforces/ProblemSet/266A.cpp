#include <iostream>
#include <vector>
#include <string>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
#define F(i,L,R) for(int i=L; i<R; i++)
#define FFE(i,L,R) for (int i = L; i >= R; i--)
#define DBG(vari) cout<<#vari<<" = "<<(vari)<<endl;

int main() {
    int n;
    while(cin>>n) {
        string s, sans;
        cin>>s;
        sans += s[0];
        F(i,1,n) if(s[i] != sans[sans.length()-1]) sans += s[i];
        cout<<s.length() - sans.length()<<endl;
    }
}
