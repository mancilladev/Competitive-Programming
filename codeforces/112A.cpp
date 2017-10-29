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
    string a, b;
    while(cin>>a>>b) {
        transform(a.begin(),a.end(),a.begin(),::tolower);
        transform(b.begin(),b.end(),b.begin(),::tolower);
        int n = 0;
        F(i,0,min(a.length(),b.length())) {
            if(a[i] < b[i]) {
                n = -1;
                break;
            }
            else if(a[i] > b[i]) {
                n = 1;
                break;
            }
        }
        cout<<n<<endl;
    }
}
