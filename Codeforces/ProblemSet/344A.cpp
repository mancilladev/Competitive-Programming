#include <iostream>
#include <vector>
#include <string>
#include <sstream>

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
        vector< pair<int,int> > vp(n);
        string s;
        F(i,0,n) {
            cin>>s;
            vp[i].first = s[0] - '0';
            vp[i].second = s[1] - '0';
        }
        
        int g = 1;
        F(i,1,n) {
            if(vp[i].first == vp[i-1].second) g++;
        }

        cout<<g<<endl;
    }
}
