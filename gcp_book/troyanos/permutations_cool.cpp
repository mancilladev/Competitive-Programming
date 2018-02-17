#include <bits/stdc++.h>
using namespace std;

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

int main () {
    vector<int> perm {1,2,3,4,5};
    do {
        cout << perm << endl;
    } while (next_permutation(begin(perm), end(perm)));
    return 0;
}
