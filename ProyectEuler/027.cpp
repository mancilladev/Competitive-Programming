#include <iostream>
#include <vector>
#include <string>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
#define F(i,L,R) for(int i=L; i<R; i++)
#define FE(i,L,R) for(int i=L; i<=R; i++)
#define FFE(i,L,R) for (int i = L; i >= R; i--)
#define DBG(vari) cout<<#vari<<" = "<<(vari)<<endl;
#define spresent(str1,str2) (str1.find(str2) != string::npos)


void sieve(vector<ll>& v) {
    v[0] = 0;
    v[1] = 0;
    for(int i=2; i*i<v.size(); i++) {
        if(v[i]) for(int j=i*i; j<v.size(); j+=i) v[j] = 0;
    }
}


int main() {
    vector<ll> v(100000, 1);
    sieve(v);

    int big = 0, N = 0;
    int mult;
    FE(a,-999,999)
        FE(b,-1000,1000) {
            F(n,0,80)
                if(n*n + a*n + b < 0 || v[n*n + a*n + b] == 0) { N = max(N, n); break; }
            if(N>big) { big = N; mult = a*b;}
        }

    DBG(mult);
    DBG(big);
}
