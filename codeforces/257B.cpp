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
    ios::sync_with_stdio(false), cin.tie(0);
    cout.precision(10), cout << fixed;

    int N, M;
    while (cin >> N >> M) {
        int size = N + M;
        function<pii(bool)> play = [&](bool fi) {
            int n = N, m = M;
            vector<int> res {fi};
            if (fi == 0) --n;
            else --m;
            for1(i, size-1) {
                bool x = (max(n, m) == n ? 0 : 1);
                if (i&1) {
                    bool b = res.back();
                    if (b == 0) x = (m ? 1 : 0);
                    if (b == 1) x = (n ? 0 : 1);
                    res.push_back(x);
                } else {
                    bool b = res.back();
                    if (b == 0) x = (n ? 0 : 1);
                    if (b == 1) x = (m ? 1 : 0);
                    res.push_back(x);
                }
                if (!x) --n;
                else --m;
            }

            int a = 0, b = 0;
            for1(i, size-1) {
                if (res[i] != res[i-1]) ++b;
                else ++a;
            }
            return make_pair(a, b);
        };
        pii p = play(0);
        pii q = play(1);
        if (q.fi > p.fi) p = q;
        cout << p.fi << ' ' << p.se << '\n';
    }
    return 0;
}
