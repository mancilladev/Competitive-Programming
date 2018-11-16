#include <bits/stdc++.h>
#define fi first
#define se second
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()
#define deb(x) cout << #x << " = " << x << endl
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define fore(i, l, r) for (int i = (int)(l); i <= (int)(r); ++i)
#define ford(i, n) for (int i = (int)(n) -1; i >= 0; --i)

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

const ll MN = 1e7;
auto isp = bitset<MN+7>{}.set();
vector<ll> primes {2};
vector<ll> p3 {2*2*2};

void sieve () {
    isp[0] = isp[1] = 0;
    for (ll i = 4; i <= MN; i += 2) isp[i] = 0;
    for (ll i = 3; i <= MN; i += 2) if (isp[i]) {
        primes.push_back(i);
        p3.push_back(i*i*i);
        for (ll j = i * i; j <= MN; j += i)
            isp[j] = 0;
    }
}

/*
bool fourDivisors (ll n) {
    ll res = 1;
    for (auto p : primes) {
        if (p * p * p > n)
            break;

        int cnt = 1;
        while (n%p == 0) {
            n /= p;
            ++cnt;
        }
        // If n = a^p * b^q then total divisors of n are (p+1)*(q+1)
        res *= cnt;

        if (res > 4)
            return false;
    }
    if (isp[n]) res *= 2;
    else if (psqr.find(n) != psqr.end()) res *= 3;
    else if (n != 1) res *= 4;
    return res == 4;
}
*/

int main (void) {
    ios::sync_with_stdio(false), cin.tie(0);
    cout.precision(10), cout << fixed;

    sieve();

    int n;
    while (cin >> n) {
        ll ans = 0;
        for (auto x : p3) {
            if (x > n) break;
            ++ans;
        }
        cout << ans << '\n';
    }
    return 0;
}
