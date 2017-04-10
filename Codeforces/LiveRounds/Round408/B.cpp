#include <algorithm>
#include <iostream>
#include <set>
typedef long long ll;
using namespace std;

int main() {
    ll N, M, K; cin >> N >> M >> K;
    set<ll> h;
    for (ll i = 0; i < M; ++i) {
        ll tmp; cin >> tmp; h.insert(tmp);
    }
    ll p = 1;
    for (ll i = 0; i < K && h.find(p) == h.end(); ++i) {
        ll a, b; cin >> a >> b;
        if (p == a) p = b;
        else if (p == b) p = a;
    }
    cout << p << '\n';
    return 0;
}
