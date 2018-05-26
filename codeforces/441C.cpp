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

    int N, M, K;
    const int MN = 307;
    const int dx[4] = {1, -1, 0, 0};
    const int dy[4] = {0, 0, 1, -1};
    while (cin >> N >> M >> K) {
        bool used[MN][MN];
        memset(used, 0, sizeof used);
        pii last = {1, 1};
        function<void(pii,int)> dfs = [&](pii p, int cnt) {
            last = p;
            if (cnt == 0) return;

            int y = p.fi, x = p.se;
            used[y][x] = true;
            cout << y << ' ' << x << ' ';

            forn(i, 4) {
                int yy = y + dy[i];
                int xx = x + dx[i];
                if (yy < 1 || yy > N || xx < 1 || xx > M) continue;
                if (used[yy][xx]) continue;

                dfs(make_pair(yy, xx), cnt - 1);
                break;
            }
        };
        forn(i, K) {
            int cnt = (N * M) / K;
            if (i+1 == K) {
                cnt += (N * M) % K;
            }
            cout << cnt << ' ';
            dfs(last, cnt);
            cout << '\n';
        }
    }
    return 0;
}
