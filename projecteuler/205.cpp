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

struct Red
{
    int quantity;
    int faces;
    map<int,int> mp;
    Red (int q, int f) : quantity(q), faces(f) {}
    void add_sum (int s) {
        ++mp[s];
    }
};

int main (void) {
    ios::sync_with_stdio(false), cin.tie(0);
    cout.precision(7), cout << fixed;

    function<void(int,int,Red&)> possibleSums = [&](int n, int s, Red& r) {
        if (n == r.quantity) {
            r.add_sum(s);
            return;
        }
        for1(v, r.faces) possibleSums(n + 1, s + v, r);
    };
    Red pyramidal = Red(9, 4);
    Red cubic = Red(6, 6);
    possibleSums(0, 0, pyramidal);
    possibleSums(0, 0, cubic);

    long double wins = 0, cnt = 0;
    for (auto p : pyramidal.mp) for (auto q : cubic.mp) {
        if (p.fi > q.fi) wins += p.se * q.se;
        cnt += p.se * q.se;
    }
    cout << wins / cnt << '\n';

    return 0;
}
