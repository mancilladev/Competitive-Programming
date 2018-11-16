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

    ll n, k, d;
    while (cin >> n >> k >> d) {
        ll kd = 1;
        bool ok = false;
        forn(i, d) {
            kd *= k;
            if (kd >= n) {
                ok = true;
                break;
            }
        }
        if (!ok) {
            cout << -1 << '\n';
            continue;
        }
        vector<vector<int>> perms;
        vector<int> temp;
        function<void(int)> genPerms = [&](int x) {
            if (x == 0) {
                perms.push_back(temp);
                return;
            }
            for1(i, k) {
                temp.push_back(i);
                genPerms(x - 1);
                temp.pop_back();
                if (sz(perms) == n) return;
            }
        };
        genPerms(d);
        forn(i, d) {
            forn(j, n) {
                cout << perms[j][i] << ' ';
            }
            cout << '\n';
        }
    }
    return 0;
}
