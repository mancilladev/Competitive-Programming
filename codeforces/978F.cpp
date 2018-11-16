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

    int n, k;
    while (cin >> n >> k) {
        vector<pii> arr(n);
        vector<int> val(n);
        forn(i, n) {
            cin >> val[i];
            arr[i] = make_pair(val[i], i);
        }
        sort(all(arr));

        vector<int> quarrel(n);
        forn(i, k) {
            int a, b; cin >> a >> b;
            --a, --b;
            if (val[a] > val[b]) quarrel[a]++;
            if (val[b] > val[a]) quarrel[b]++;
        }

        int lst = 0;
        vector<int> res(n);
        for1(i, n-1) {
            if (arr[i].fi > arr[lst].fi) lst = i;
            res[arr[i].se] = lst - quarrel[arr[i].se];
        }
        for (auto it : res) cout << it << ' ';
        cout << '\n';
    }
    return 0;
}
