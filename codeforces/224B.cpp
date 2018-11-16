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
    map<int,int> mp;
    void add (int x) {
        mp[x] += 1;
        // deb(mp);
    }
    void remove (int x) {
        mp[x] -= 1;
        if (mp[x] == 0) {
            mp.erase(mp.find(x));
        }
    }
    int size () {
        return sz(mp);
    }
};

int main (void) {
    ios::sync_with_stdio(false), cin.tie(0);
    cout.precision(10), cout << fixed;

    int n, k;
    while (cin >> n >> k) {
        vector<int> arr(n);
        forn(i, n) cin >> arr[i];

        Red red = Red();
        int r = 0;
        pii ans {-1, -1};
        forn(l, n) {
            if (l) red.remove(arr[l-1]);
            while (r < n && red.size() < k) {
                red.add(arr[r++]);
            }
            if (red.size()==k && (ans.fi==-1 || ans.se-ans.fi+1>r-l)) {
                ans = make_pair(l+1, r);
            }
        }
        cout << ans.fi << ' ' << ans.se << '\n';
    }
    return 0;
}
