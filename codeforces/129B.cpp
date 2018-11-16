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

    int n, m;
    while (cin >> n >> m) {
        vector<int> adj[107];
        forn(i, m) {
            int a, b; cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        vector<bool> kicked(107, false), vis(107, false);
        vector<int> kick, tied(107);
        function<void(int,int)> dfs = [&](int a, int p) {
            vis[a] = true;
            int tied = 0;
            for (auto b : adj[a]) {
                if (!kicked[b]) ++tied;
                if (b == p || vis[b] || kicked[b]) continue;
                dfs(b, a);
            }
            if (tied == 1)
                kick.push_back(a);
        };
        int ans = 0;
        while (true) {
            kick.clear();
            fill(all(vis), false);
            for1(a, n) {
                if (kicked[a] || vis[a]) continue;
                dfs(a, -1);
            }
            if (sz(kick) == 0) break;
            for (auto k : kick) kicked[k] = true;
            ++ans;
        }
        cout << ans << '\n';
    }
    return 0;
}
