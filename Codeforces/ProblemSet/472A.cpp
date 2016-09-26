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


void sieve(vector<bool>& v) {
    v[0] = 0;
    v[1] = 0;
    for(int i=2; i*i<=v.size(); i++)
        if(v[i]) for(int j=i*i; j<=v.size(); j+=i) v[j] = 0;
}


int main() {
    ll n;
    vector<bool> v(1000001, 1);
    sieve(v);
    while(cin>>n) {
        F(i,4,n) if(!v[i] && !v[n-i]) {
            cout<<i<<" "<<n-i<<endl;
            break;
        }
    }
}
