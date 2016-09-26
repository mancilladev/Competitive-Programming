#include <iostream>
using namespace std;
#define ll long long

int main() {
    ll a;
    cin >> a;
    while(cin>>a) {
        ll x, y, z;
        ll sum = 0;
        for(int i=0; i<a; i++) {
            cin >> x >> y >> z;
            sum += (x*z);
        }
        cout << sum << endl;
    }
    return 0;
}
