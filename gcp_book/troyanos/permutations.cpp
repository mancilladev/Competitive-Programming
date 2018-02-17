#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
const int INF = (int)1e9 + 7;

// Vector
template < typename T >
ostream &operator << ( ostream & os, const vector < T > &v ) {
    os << '{';
    typename vector< T > :: const_iterator it;
    for ( it = begin(v); it != end(v); ++it ) {
        if ( it != begin(v) ) os << ", ";
        cout << *it;
    }
    return os << '}';
}

#define deb(x) cerr << #x << " = " << x << endl
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()
#define sq(x) (x) * (x)
#define pb push_back
#define f first
#define s second
#define endl '\n'

#define UNIQUE(a) sort(all(a)), (a).erase(unique(all(a)), (a).end())
#define FOR(i, a, b) for (int i(a), b_(b); i < b_; ++i)
#define REP(i, n) FOR (i, 0, n)
#define FORD(i, a, b) for (int i(a), b_(b); i >= b_; --i)

const int N = 1e5 + 7;
const int n = 3;
bool chosen[n+1];
vector<int> permutation;

void search() {
    if (sz(permutation) == n) {
        cout << permutation << endl;
        return;
    }
    FOR(i, 1, n+1) {
        if (chosen[i]) continue;
        chosen[i] = true;
        permutation.pb(i);
        search();
        chosen[i] = false;
        permutation.pop_back();
    }
}

int main(void) {
    search();
    return 0;
}
