#include <bits/stdc++.h>
using namespace std;
#define PB push_back
typedef long long ll;
typedef long double ld;
const ll INF = ll(1e18);
const int MAX = (1e7);
int limit = 10000000;

struct Node {
    ll n;
    ll phi;
} res, node;

bool isPermutation(ll a, ll b) {
    vector<int> arr(10, 0);
    while (a) {
        ++arr[a % 10];
        a /= 10;
    }
    while (b) {
        --arr[b % 10];
        b /= 10;
    }
    for (int d: arr) if (d)
            return false;
    return true;
}

int main() {
    vector<ll> phi(limit+1);
    for (int i = 0; i <= limit; ++i)
        phi[i] = i;

    for (int n = 2; n <= limit; ++n) {
        if (phi[n] == n) for (int i = n; i <= limit; i += n) {
            phi[i] = phi[i] / n * (n - 1);
        }
    }

    Node res = {87109, 79180};
    for (int n = 2; n < MAX; ++n) {
        if (isPermutation(phi[n], n) && n * 1.0 / phi[n] < res.n * 1.0 / res.phi) {
            res = {n, phi[n]};
        }
    }
    cout << res.n << endl;

    return 0;
}
