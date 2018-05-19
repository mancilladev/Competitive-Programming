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

const int MN = 2e5 + 7;
ll N;

int getScore (string s) {
    map<char, int> cnt;
    for (auto c : s) cnt[c] += 1;
    auto best = *max_element(cnt.begin(), cnt.end(),
        [](const pii& p1, const pii& p2) {
            return p1.se < p2.se;
        });
    if (N == 1 && best.se == sz(s)) s.pop_back();
    return (int) min((ll)best.se + N, (ll)sz(s));
}

int main (void) {
    while (cin >> N) {
        vector<pii> score;
        REP(i, 3) {
            string s;
            cin >> s;
            score.emplace_back(getScore(s), i);
        }
        sort(all(score), greater<pii>());
        int ans = (score[0].fi == score[1].fi ? -1 : score[0].se);
        if (ans == -1) cout << "Draw\n";
        if (ans == 0) cout << "Kuro\n";
        if (ans == 1) cout << "Shiro\n";
        if (ans == 2) cout << "Katie\n";
    }
    return 0;
}
