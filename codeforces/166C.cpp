#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
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
using namespace __gnu_pbds;
typedef long long ll;
typedef pair<int,int> pii;
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template < typename F, typename S >
ostream& operator << ( ostream& os, const pair< F, S > & p ) {
    return os << "(" << p.first << ", " << p.second << ")";
}
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
template < typename T >
ostream &operator << ( ostream & os, const tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update> &v ) {
    os << "[";
    typename tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update> :: const_iterator it;
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

    int n, x;
    const int MN = 1e5;
    while (cin >> n >> x) {
        deque<int> arr(n);
        bool ok = false;
        forn(i, n) {
            cin >> arr[i];
            if (arr[i] == x) ok = true;
        }
        if (!ok) arr.push_back(x);
        sort(all(arr));
        int ans = !ok;
        while (arr[(sz(arr)+1)/2-1] < x) arr.push_back(MN), ++ans;
        while (arr[(sz(arr)+1)/2-1] > x) arr.push_front(1), ++ans;
        cout << ans << '\n';
    }
    return 0;
}
