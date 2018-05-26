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

    string S;
    int a, b;
    while (cin >> S >> a >> b) {
        int n = sz(S);
        vector<int> rema(n+1, 0), remb(n+1, 0);
        for1(i, n) {
            int c = S[i-1] - '0';
            rema[i] = (rema[i-1] * 10 + c)%a;
        }
        int l = 1;
        ford(i, n) {
            int c = S[i] - '0';
            remb[i] = (c * l + remb[i+1])%b;
            l *= 10;
            l %= b;
        }
        int pos = -1;
        forn(i, n-1) if (rema[i+1] == 0 && remb[i+1] == 0) {
            if (S[0] == '0') break;
            if (S[i+1] == '0') continue;
            pos = i+1;
            break;
        }
        if (pos == -1) cout << "NO\n";
        else {
            cout << "YES\n";
            forn(i, pos) cout << S[i];
            cout << '\n';
            fore(i, pos, n-1) cout << S[i];
            cout << '\n';
        }
    }
    return 0;
}
