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

    int m;
    string s;
    while (cin >> s >> m) {
        vector<int> valid(11);
        forn(i, 10) valid[i+1] = (s[i] == '1');
        vector<int> res;
        vector<int> cnt(2, 0);
        function<bool(int,int)> dfs = [&](int k, int last) {
            if (k == m) return true;
            for1(x, 10) {
                if (!valid[x] || x == last) continue;
                if (cnt[k&1] + x <= cnt[!(k&1)]) continue;
                cnt[k&1] += x;
                if (dfs(k+1, x)) {
                    res.push_back(x);
                    return true;
                }
                cnt[k&1] -= x;
            }
            return false;
        };
        if (!dfs(0, -1)) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            reverse(all(res));
            for (auto it : res) cout << it << ' ';
            cout << '\n';
        }
    }
    return 0;
}
