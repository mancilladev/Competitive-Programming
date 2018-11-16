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

int main (void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n;
    while (cin >> n) {
        function<ll(pii)> md = [&](const pii p) {
            return abs(p.fi) + abs(p.se);
        };
        function<pii(pii)> abspair = [&](const pii p) {
            return make_pair(abs(p.fi), abs(p.se));
        };

        vector<pii> arr(n);
        int cx = 0, cy = 0;
        forn(i, n) {
            cin >> arr[i].fi >> arr[i].se;
            if (arr[i].fi) ++cx;
            if (arr[i].se) ++cy;
        }
        sort(all(arr), [&](const pii p1, const pii p2) {
            ll a = md(p1);
            ll b = md(p2);
            if (a == b) {
                return abspair(p1) < abspair(p2);
            }
            return a < b;
        });

        cout << 2*n + 2*cx + 2*cy << '\n';
        for (auto p : arr) {
            if (p.fi) {
                cout << 1 << ' ';
                cout << abs(p.fi) << ' ';
                cout << (p.fi > 0 ? 'R' : 'L');
                cout << '\n';
            }
            if (p.se) {
                cout << 1 << ' ';
                cout << abs(p.se) << ' ';
                cout << (p.se > 0 ? 'U' : 'D');
                cout << '\n';
            }
            cout << 2 << '\n';
            if (p.fi) {
                cout << 1 << ' ';
                cout << abs(p.fi) << ' ';
                cout << (p.fi > 0 ? 'L' : 'R');
                cout << '\n';
            }
            if (p.se) {
                cout << 1 << ' ';
                cout << abs(p.se) << ' ';
                cout << (p.se > 0 ? 'D' : 'U');
                cout << '\n';
            }
            cout << 3 << '\n';
        }
    }
    return 0;
}
