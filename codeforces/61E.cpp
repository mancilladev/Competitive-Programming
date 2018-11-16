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
    ll query (int b) {
        ll sum = 0;
        for (; b > 0; b -= b&(-b)) {
            sum += bit[b];
        }
        return sum;
    }
    ll query (int a, int b) {
        return query(b) - query(a-1);
    }
};

int main (void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n;
    while (cin >> n) {
        vector<int> arr(n);
        vector<int> brr;
        forn(i, n) {
            cin >> arr[i];
            brr.push_back(arr[i]);
        }
        sort(all(brr));
        brr.erase(unique(all(brr)), brr.end());
        unordered_map<int,int> mp;
        forn(i, sz(brr)) mp[brr[i]] = i+1;
        forn(i, n) arr[i] = mp[arr[i]];

        Fenwick ftl = Fenwick(n);
        vector<ll> l(n);
        forn(i, n) {
            l[i] = ftl.query(arr[i]+1, n);
            ftl.update(arr[i], 1);
        }

        Fenwick ftr = Fenwick(n);
        vector<ll> r(n);
        ford(i, n) {
            r[i] = ftr.query(arr[i]);
            ftr.update(arr[i], 1);
        }

        ll res = 0;
        forn(i, n) res += l[i] * r[i];
        cout << res << '\n';
    }
    return 0;
}
