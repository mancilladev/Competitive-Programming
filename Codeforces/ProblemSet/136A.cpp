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
    int n;
    while(cin>>n) {
        vi vfirst(n), vsec(n);
        F(i,0,n) cin>>vfirst[i];
        F(i,0,n) vsec[vfirst[i]-1] = i+1;
        F(i,0,n-1) cout<<vsec[i]<<" ";
        cout<<vsec[n-1]<<endl;
    }
}
