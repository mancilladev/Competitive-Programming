#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void) {
    ll n; cin >> n;
    vector<ll> v(n-1);
    for (auto& x : v) cin >> x;
    ll sum = accumulate(begin(v), end(v), 0LL);
    ll gauss = n * (n+1) / 2;
    cout << gauss - sum << endl;
    return 0;
}
