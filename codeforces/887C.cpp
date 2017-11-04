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
ostream &operator << ( ostream & os, const deque< T > &v ) {
    os << "{";
    typename deque< T > :: const_iterator it;
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
vector<int> arr(25);
vector<vector<int>> posi = {
    {1,3,5,7,9,11,24,22},
    {2,4,6,8,10,12,23,21},
    {13,14,5,6,17,18,21,22},
    {15,16,7,8,19,20,23,24},
    {9,10,19,17,4,3,14,16},
    {11,12,20,18,2,1,13,15}
};

bool check(vector<int> A) {
    FOR(i, 1, 7) {
        FOR(j, 4*i-3, 4*i) if (A[j] != A[4*i]) return 0;
    }
    return 1;
}

int main(void) {
    ios_base::sync_with_stdio(0), cin.tie(nullptr);
    FOR(i, 1, 25) cin >> arr[i];
    for (auto v : posi) {
        vector<int> A = arr;
        REP(i, sz(v)) A[v[i]] = arr[v[(i+2)%8]];
        if (check(A)) return cout << "YES\n", 0;
        REP(i, sz(v)) A[v[i]] = arr[v[(i+6)%8]];
        if (check(A)) return cout << "YES\n", 0;
    }
    cout << "NO\n";
    return 0;
}
