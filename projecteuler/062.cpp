#include <bits/stdc++.h>
using namespace std;
#define PB push_back
typedef long long ll;
typedef long double ld;
const ll INF = ll(1e18);
const int MAX = 10000;
int N = 3;

bool isP(ll x, ll y) {
    int digits[10] {0};
    while (x)
        digits[x%10]++, x /= 10;
    while (y)
        digits[y%10]--, y /= 10;
    for (int i = 0; i < 10; ++i)
        if (digits[i] != 0)
            return false;
    return true;
}

int main() {

    for (ll a = 2; a < MAX; ++a) {
        ll a3 = a*a*a;
        for (ll b = a+1; b < MAX; ++b) {
            if (isP(a3, b*b*b)) for (ll c = b+1; c < MAX; ++c) {
                if (isP(a3, c*c*c)) for (ll d = c+1; d < MAX; ++d) {
                    if (isP(a3, d*d*d)) for (ll e = d+1; e < MAX; ++e) {
                        if (isP(a3, e*e*e)) {
                            printf("> %lld = %lld %lld %lld %lld %lld\n", a3, a, b, c, d, e);
                            return 0;
                        }
                    }
                }
            }
        }
    }

    return 0;
}
