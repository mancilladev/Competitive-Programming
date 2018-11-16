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

// COUT << PAIR
template < typename F, typename S > ostream& operator << ( ostream& os, const pair< F, S > & p ) {return os << "(" << p.first << ", " << p.second << ")"; }
// COUT << VECTOR
template < typename T > ostream &operator << ( ostream & os, const vector< T > &v ) {os << "{"; typename vector< T > :: const_iterator it; for( it = v.begin(); it != v.end(); it++ ) {if( it != v.begin() ) os << ", "; os << *it; } return os << "}"; }
// COUT << SET
template < typename T > ostream &operator << ( ostream & os, const set< T > &v ) {os << "["; typename set< T > :: const_iterator it; for ( it = v.begin(); it != v.end(); it++ ) {if( it != v.begin() ) os << ", "; os << *it; } return os << "]"; }
// COUT << MAP
template < typename F, typename S > ostream &operator << ( ostream & os, const map< F, S > &v ) {os << "["; typename map< F , S >::const_iterator it; for( it = v.begin(); it != v.end(); it++ ) {if( it != v.begin() ) os << ", "; os << it -> first << " = " << it -> second ; } return os << "]"; }

const long long INF = (ll)2e9 + 7;
const long long LLINF = (ll)4e18 + 7;
const double pi = acos(-1.0);

int main () {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    cout.precision(10), cout << fixed;

    int n;
    while (cin >> n) {
        vector<ll> arr(n);
        forn(i, n) cin >> arr[i];

        ll res = -2e9;
        vector<ll> dp(n+2, 0);
        ford(i, n-1) {
            dp[i] = arr[i] + arr[i+1] + dp[i+2];
            res = max(res, dp[i]);
            dp[i] = max(0LL, dp[i]);
        }
        cout << res << endl;
    }
    return 0;
}
