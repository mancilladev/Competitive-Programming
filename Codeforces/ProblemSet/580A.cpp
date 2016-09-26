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
        vector<ll> v(n);
        F(i,0,n) cin>>v[i];

        int seq = 1, temp = 1;
        F(i,1,n) {
            if(v[i] >= v[i-1]) temp++;
            else {
                seq = max(seq, temp);
                temp = 1;
            }
        }
        seq = max(seq, temp);

        cout<<seq<<endl;
    }
}
