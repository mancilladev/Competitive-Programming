#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
#define F(i,L,R) for(int i=L; i<R; i++)

int main() {
    ll n,m;
    while(cin>>n>>m) {
        vector<ll> v(m);
        F(i,0,m) cin>>v[i];

        ll ans = v[0]-1;
        F(i,1,m) {
            if(v[i] >= v[i-1]) ans += v[i] - v[i-1];
            else ans += n+v[i] - v[i-1];
        }

        cout<<ans<<endl;
    }
}
