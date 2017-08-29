#include <iostream>
using namespace std;
typedef long long ll;

int main() {
    ll n, k;
    while(cin>>n>>k) {
        ll odds = n/2;
        ll evens = n/2;
        if(n%2) odds++;
        if(k>odds) cout<<(k-odds)*2<<endl;
        else cout<<k*2-1<<endl;
    }
}
