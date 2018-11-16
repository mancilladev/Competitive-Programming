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

// Counting inversions

struct Fenwick
{
    int size;
    vector<int> bit;
    Fenwick (int n) {
        size = n;
        bit.resize(size+1);
    }
    void update (int p, int v) {
        for (; p <= size; p += p&(-p)) {
            bit[p] += v;
        }
    }
    int query (int b) {
        int sum = 0;
        for (; b > 0; b -= b&(-b)) {
            sum += bit[b];
        }
        return sum;
    }
    int query (int a, int b) {
        return query(b) - query(a);
    }
};

int main (void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> arr(n);
        int maxi = 0;
        forn(i, n) {
            cin >> arr[i];
            maxi = max(maxi, arr[i]);
        }

        ll ans = 0;
        Fenwick ft = Fenwick(maxi);
        forn(i, n) {
            ans += ft.query(arr[i], maxi);
            ft.update(arr[i], 1);
        }
        cout << ans << '\n';
    }
    return 0;
}
