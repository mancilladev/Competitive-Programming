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


int GCD(int a, int b) {
    if(b==0) return a;
    return GCD(b,a%b);
}


int main() {
    vi v(2);
    int a, b, c;
    while(cin>>v[0]>>v[1]>>c) {
        int i = 0;
        while(c > 0) {
            c -= GCD(v[i%2],c);
            i++;
        }
        cout<<++i%2<<endl;
    }
}
