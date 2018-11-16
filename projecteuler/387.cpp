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

template < typename F, typename S >
ostream& operator << ( ostream& os, const pair< F, S > & p ) {
    return os << "(" << p.first << ", " << p.second << ")";
}
template < typename T >
ostream &operator << ( ostream & os, const vector< T > &v ) {
    os << "{";
    typename vector< T > :: const_iterator it;
    for( it = v.begin(); it != v.end(); it++ ) {
        if( it != v.begin() ) os << ", ";
        os << *it;
    }
    return os << "}";
}
template < typename T >
ostream &operator << ( ostream & os, const set< T > &v ) {
    os << "[";
    typename set< T > :: const_iterator it;
    for ( it = v.begin(); it != v.end(); it++ ) {
        if( it != v.begin() ) os << ", ";
        os << *it;
    }
    return os << "]";
}
template < typename F, typename S >
ostream &operator << ( ostream & os, const map< F, S > &v ) {
    os << "[";
    typename map< F , S >::const_iterator it;
    for( it = v.begin(); it != v.end(); it++ ) {
        if( it != v.begin() ) os << ", ";
        os << it -> first << " = " << it -> second ;
    }
    return os << "]";
}

const int BP = 1e7; // Biggest Prime
auto isp = bitset<BP+7>{}.set();

void sieve () {
    isp[0] = isp[1] = 0;
    for (ll i = 4; i <= BP; i += 2) isp[i] = 0;
    for (ll i = 3; i * i <= BP; i += 2) if (isp[i]) {
        for (ll j = i * i; j <= BP; j += i)
            isp[j] = 0;
    }
}

bool is_prime (ll n) {
    if (n < 2) return false;
    if (n <= BP) return isp[n];
    if ((n&1) == 0 || n%3 == 0) return false;

    for (ll i = 5; i * i <= n; i += 6)
        if (n % i == 0 || n % (i + 2) == 0) return false;
    return true;
}

int sumdigits (ll n) {
    int s = 0;
    while (n) {
        s += n % 10;
        n /= 10;
    }
    return s;
}

bool isHarshad (int n) {
    if (n == 0) return true;
    int s = sumdigits(n);
    if (n%s != 0) return false;
    return isHarshad(n/10);
}

bool isStrong (int n) {
    int s = sumdigits(n);
    if (!isp[n/s]) return false;
    return isHarshad(n);
}


int main (void) {
    ios::sync_with_stdio(false), cin.tie(0);
    cout.precision(10), cout << fixed;

    sieve();

    vector<ll> harshad;
    vector<ll> last {1,2,3,4,5,6,7,8,9};
    fore(size, 2, 13) {
        vector<ll> v;
        for (auto x : last) {
            forn(i, 10) {
                ll n = x * 10 + i;
                if (n % sumdigits(n) == 0)
                    v.push_back(n);
            }
        }
        last = v;
        harshad.insert(end(harshad), all(last));
    }

    vector<ll> strong;
    for (auto h : harshad) if (is_prime(h/sumdigits(h))) {
        strong.push_back(h);
    }

    vector<ll> res;
    for (auto h : strong) forn(i, 10) {
        ll x = 10 * h + i;
        if (is_prime(x))
            res.push_back(x);
    }

    ll ans = 0;
    for (auto x : res) ans += x;
    cout << ans << '\n';
    return 0;
}
