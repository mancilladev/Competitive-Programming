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

const ll MN = 1e7 + 7;
vector<bool> isp(MN, 1);

int main (void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;

    vector<int> primes {2};
    isp[0] = 0; isp[1] = 0;
    for (ll i = 4; i < MN; i += 2) isp[i] = 0;
    for (ll i = 3; i < MN; i += 2) if (isp[i]) {
        primes.push_back(i);
        for (ll j = i * i; j < MN; j += i) isp[j] = 0;
    }

    int n, m;
    while (cin >> n) {
        vector<int> cnt(MN, 0);
        forn(i, n) {
            int x; cin >> x;
            ++cnt[x];
        }
        vector<ll> f(MN+1, 0);
        for (auto p : primes) for (ll j = p; j < MN; j += p) {
            f[p] += cnt[j];
        }
        for1(i, MN) f[i] += f[i-1];
        cin >> m;
        forn(i, m) {
            int l, r; cin >> l >> r;
            l = min(l, sz(f)-1);
            r = min(r, sz(f)-1);
            cout << f[r] - f[l-1] << '\n';
        }
    }
    return 0;
}
