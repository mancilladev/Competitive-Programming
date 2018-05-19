#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = (int)1e9 + 7;
#define deb(x) cerr << #x << " = " << x << endl
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()
#define sq(x) (x) * (x)
#define fi first
#define se second
#define UNIQUE(a) sort(all(a)), (a).erase(unique(all(a)), (a).end())
#define FOR(i, a, b) for (int i(a); i < b; ++i)
#define REP(i, n) FOR (i, 0, n)
#define FORD(i, a, b) for (int i(a); i >= b; --i)

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

const int MN = 3e5 + 7;
ll N, X, Y;
vector<int> adj[MN];

int main (void) {
    while (cin >> N >> X >> Y) {
        memset(adj, 0, sizeof adj);
        REP(i, N-1) {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        vector<int> sub_size(N+7), invalid(N+7);
        function<int(int,int)> dfs = [&](int u, int pr) {
            sub_size[u] = 1;
            invalid[u] = (u == X);
            for (auto& to : adj[u]) {
                if (to == pr) continue;
                sub_size[u] += dfs(to, u);
                invalid[u] |= invalid[to];
            }
            return sub_size[u];
        };
        dfs(Y, -1);

        ll unreachable = -1;
        for (int to : adj[Y]) {
            if (invalid[to]) {
                unreachable = sub_size[Y] - sub_size[to]; // all but this subtree
                break;
            }
        }
        cout << 1LL * N * (N-1) - sub_size[X] * unreachable << '\n';
    }
    return 0;
}
