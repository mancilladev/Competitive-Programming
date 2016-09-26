#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
#define F(i,L,R) for(int i=L; i<R; i++)
#define FE(i,L,R) for(int i=L; i<=R; i++)
#define FFE(i,L,R) for (int i = L; i >= R; i--)
#define DBG(vari) cout<<#vari<<" = "<<(vari)<<endl;
#define spresent(str1,str2) (str1.find(str2) != string::npos)

int main() {
    int n,m;
    while(cin>>n>>m) {
        int diff = 2000;
        vi v(m);
        F(i,0,m) cin>>v[i];
        sort(v.begin(),v.end());
        FE(i,0,m-n) diff = min(v[i+n-1]-v[i],diff);
        cout<<diff<<endl;
    }
}
