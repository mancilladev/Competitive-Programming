#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
const int INF = (int)1e9 + 7;

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
int n = 10;
vector<int> subset, elems {100,54,62,77};

void printElems() {
    cout << '{';
    REP(i, sz(subset)) {
        if (i) cout << ", ";
        cout << elems[subset[i]];
    }
    cout << "}\n";
}

void search(int k) {
    if (k == n) {
        cout << subset << endl;
        return;
    }
    subset.push_back(k);
    search(k+1);
    subset.pop_back();
    search(k+1);
}

int main(void) {
    search(0);
    return 0;
}
