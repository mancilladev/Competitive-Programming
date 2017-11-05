#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
template <class T> using min_queue = priority_queue<T, vector<T>, greater<T>>;
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// PAIR
template < typename F, typename S >
ostream& operator << ( ostream& os, const pair< F, S > & p ) {
    return os << "(" << p.first << ", " << p.second << ")";
}

// VECTOR
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

// SET
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

// MAP
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


const int INF = (int)1e9 + 7;
const long long LLINF = (ll)4e18 + 7;
const double pi = acos(-1.0);

#define deb(x) cerr << #x << " = " << x << endl
#define sz(a) static_cast<int>((a).size())
#define all(a) (a).begin(), (a).end()
#define sq(x) (x) * (x)
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define endl '\n'

#define UNIQUE(a) sort(all(a)), (a).erase(unique(all(a)), (a).end())
#define FOR(i, a, b) for (int i(a), b_(b); i < b_; ++i)
#define REP(i, n) FOR (i, 0, n)
#define FORD(i, a, b) for (int i(a), b_(b); i >= b_; --i)

const int N = 1e5+7;
int n;
char c;

int king() {
    int M[n][n], maxi = 0;
    memset(M, -1, sizeof M);
    REP(j, n) REP(i, n) {
        unordered_set<int> colors;
        FOR(x, i-1, i+2) FOR(y, j-1, j+2) {
            if (min(x,y) < 0 || max(x,y) >= n
                || (x == i && y == j) || M[y][x] == -1)
                continue;
            colors.insert(M[y][x]);
        }
        REP(k, n*n) if (colors.find(k) == colors.end()) {
            M[j][i] = k;
            maxi = max(maxi, k);
            break;
        }
    }
    REP(j, n) {
        REP(i, n) cout << M[j][i];
        cout << endl;
    }
    return maxi + 1;
}

int main(void) {
    ios_base::sync_with_stdio(0), cin.tie(nullptr);
    while (cin >> n >> c) {
        if (c == 'N'){
            if (n < 3) cout << 1 << endl;
            else cout << 2 << endl;
        }
        if (c == 'R' || c == 'B') {
            cout << n << endl;
        }
        if (c == 'K') {
            if (n == 1) cout << 1 << endl;
            else cout << 4 << endl;
        }
    }
    return 0;
}
