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
#define FOR(i, a, b) for (int i(a); i < b; ++i)
#define REP(i, n) FOR (i, 0, n)
#define FORD(i, a, b) for (int i(a); i >= b; --i)

const int MN = 1e3 + 7;
int N, M, a[MN][MN];
vector<pii> offset {{-1,0}, {0,1}, {0,-1}, {1,0}};

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

struct DSU {
    int size[MN*MN], parent[MN*MN];
    void make_set (int v) {
        parent[v] = v;
        size[v] = 1;
    }
    int find_set (int v) {
        if (parent[v] == v) return v;
        return parent[v] = find_set(parent[v]);
    }
    void union_set (int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a != b) {
            if (size[a] < size[b])
                swap(a, b);
            parent[b] = a;
            size[a] += size[b];
        }
    }
    int size_set (int v) {
        return size[find_set(v)];
    }
};

int main (void) {
    cin >> N >> M;
    DSU dsu = DSU();
    FOR(i, 1, 1+N) {
        FOR(j, 1, 1+M) {
            cin >> a[i][j];
            dsu.make_set(i*M + j);
            if (!a[i][j]) continue;
            if (a[i][j-1]) dsu.union_set(i*M+j, i*M+(j-1));
            if (a[i-1][j]) dsu.union_set(i*M+j, (i-1)*M+j);
        }
    }
    int ans = 0;
    vector<int> comp;
    FOR(i, 1, 1+N) {
        FOR(j, 1, 1+M) {
            if (a[i][j]) continue;
            comp.clear();
            for (auto off : offset) {
                int y = i+off.fi;
                int x = j+off.se;
                if (a[y][x]) {
                    int u = dsu.find_set(y*M + x);
                    comp.push_back(u);
                }
            }
            sort(all(comp));
            comp.erase(unique(all(comp)), comp.end());
            int sum = 0;
            if (sz(comp))
                for (auto it : comp) sum += dsu.size[it];
            ans = max(ans, sum + 1);
        }
    }
    cout << ans << '\n';
    return 0;
}
