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
    int a, b;
    while(cin>>a>>b) {
        int c = 0;
        while(a >= b) {
            c += b;
            a -= b;
            a++;
        }
        cout<<c+a<<endl;
    }
}
