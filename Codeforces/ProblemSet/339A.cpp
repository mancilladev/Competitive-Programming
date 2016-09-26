#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
#define F(i,L,R) for(int i=L; i<R; i++)
#define FFE(i,L,R) for (int i = L; i >= R; i--)
#define DBG(vari) cout<<#vari<<" = "<<(vari)<<endl;

int main() {
    string s;
    while(cin>>s) {
        vi v;
        for(int i = 0; i < s.length(); i+=2) {
            v.push_back(s[i]-'0');
        }
        sort(v.begin(), v.end());
        F(i,0,v.size()-1) cout<<v[i]<<"+";
        cout<<v[v.size()-1]<<endl;
    }
}
