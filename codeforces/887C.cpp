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

struct Face {
    deque<int> left;
    deque<int> right;
    void rotate(int x) {
        if (x == 0) REP(i, 2) {
            left.pb(left.front());
            left.pop_front();
        } else REP(i, 2) {
            right.pb(right.front());
            right.pop_front();
        }
    }
    int equal() {
        for (int i = 0; i < sz(left); i+=2) {
            if (left[i] != right[i] ||
                left[i] != left[i+1] ||
                right[i] != right[i+1]) {
                return 0;
            }
        }
        return 1;
    }
} ver, hor;

void print() {
    cerr << "V\n";
    cerr << ver.left << endl;
    cerr << ver.right << endl;
    cerr << "H\n";
    cerr << hor.left << endl;
    cerr << hor.right << endl;
    cerr << endl;
    cerr << "--------------------\n\n";
}

const int N = 1e5+7;
int n = 24;

void changeHor() {
    // front
    hor.left[2] = ver.left[2];
    hor.left[3] = ver.right[2];
    hor.right[2] = ver.left[3];
    hor.right[3] = ver.right[3];
    // back
    hor.left[6] = ver.left[6];
    hor.left[7] = ver.right[6];
    hor.right[6] = ver.left[7];
    hor.right[7] = ver.right[7];
}

void changeVer() {
    // front
    ver.left[2] = hor.left[2];
    ver.right[2] = hor.left[3];
    ver.left[3] = hor.right[2];
    ver.right[3] = hor.right[3];
    // back
    ver.left[6] = hor.left[6];
    ver.right[6] = hor.left[7];
    ver.left[7] = hor.right[6];
    ver.right[7] = hor.right[7];
}

int check() {
    REP(x, 2) REP(i, 4) {
        hor.rotate(x);
        changeVer();
        if (ver.equal() && hor.equal()) return 1;
    }
    REP(x, 2) REP(i, 4) {
        ver.rotate(x);
        changeHor();
        if (ver.equal() && hor.equal()) return 1;
    }
    return 0;
}


int main(void) {
    ios_base::sync_with_stdio(0), cin.tie(nullptr);
    int vi = 0, vh = 0;
    REP(i, 6) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if (i < 3 || i == 5) {
            if (i == 5) swap(a, b), swap(c, d);
            ver.left.pb(a);
            ver.right.pb(b);
            ver.left.pb(c);
            ver.right.pb(d);
            vi++;
        }
        if (i == 1 || i > 2) {
            hor.left.pb(a);
            hor.left.pb(b);
            hor.right.pb(c);
            hor.right.pb(d);
            if (i == 3) hor.rotate(0), hor.rotate(1);
            vh++;
        }
    }
    if (check()) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}
