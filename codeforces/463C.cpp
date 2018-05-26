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

int arr[2007][2007];

int main (void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n;
    while (cin >> n) {
        function<int(int,int,int)> getd = [&](int y, int x, int d) {
            assert(d == 1 || d == 2);
            return (d == 1 ? y + x : y + (n - x - 1));
        };
        vector<ll> d1(2*(n-1)+1, 0), d2(2*(n-1)+1, 0);
        forn(i, n) forn(j, n) {
            cin >> arr[i][j];
            d1[getd(i, j, 1)] += arr[i][j];
            d2[getd(i, j, 2)] += arr[i][j];
        }
        vector<pii> v(2);
        vector<ll> res(2, -1);
        forn(i, n) forn(j, n) {
            ll val = d1[getd(i, j, 1)] + d2[getd(i, j, 2)] - arr[i][j];
            ll c = (i+j)&1;
            if (val > res[c]) {
                res[c] = val;
                v[c] = make_pair(i+1, j+1);
            }
        }
        cout << res[0] + res[1] << '\n';
        cout << v[0].fi << ' ' << v[0].se << ' ';
        cout << v[1].fi << ' ' << v[1].se << '\n';
    }
    return 0;
}
