#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

ll s(ll n) { return n*(n+1)/2; }

int main() {
    ll T,N;
    cin>>T;
    while(T--) {
        cin>>N;
        N--;
        ll res = 0;
        res += 3*s(N/3);
        res += 5*s(N/5);
        res -= 15*s(N/15);
        cout<<res<<endl;
    }
    return 0;
}
