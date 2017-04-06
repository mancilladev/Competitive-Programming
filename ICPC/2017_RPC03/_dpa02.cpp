#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
#include <set>
#define MAX 1000000000000
typedef long long ll;
using namespace std;
set<ll> perfects = {6, 28, 496, 8128, 33550336, 8589869056};

bool divisibleByPerfect(ll n) {
    for (ll p: perfects)
        if (n % p == 0)
            return true;
    return (n%20 == 0);
}

bool possibleDeficient(ll n) {
    return (n%2 != 0 && n%3 != 0 && n%5 != 0);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;

    while (t--) {
        ll n; cin >> n;

        if (perfects.find(n) != perfects.end()) {
            cout << "_perfect\n";
            continue;
        }
        if (divisibleByPerfect(n)) {
            cout << "_abundant\n";
            continue;
        }
        if (possibleDeficient(n)) {
            cout << "_deficient\n";
            continue;
        }

        ll sum = 1;

        for (ll i = 2; i <= sqrt(n); ++i) {
            if (n%i == 0) {
                if (i == n/i)
                    sum += i;
                else
                    sum += i + n/i;
            }
        }

        if (sum > n) cout << "abundant\n";
        else cout << "deficient\n";
    }

    return 0;
}
