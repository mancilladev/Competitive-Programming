#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <utility>
using namespace std;
#define F first
#define S second
#define PB push_back
#define MP make_pair
typedef long long ll;
const ll INF = ll(1e18);

ll gauss(ll x) {
    return x * (x+1) / 2;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    ll N, K; cin >> N >> K;
    ll left = 4*60 - K;
    while (5 * gauss(N) > left)
        --N;

    cout << N << '\n';

    return 0;
}
