#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define error(x) cerr << #x << " = " << x << endl
#define sz(x) (int)(x).size()
#define eb emplace_back
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

const int MOD = 1e9 + 7;

int main(void) {
    int N, Q; cin >> N >> Q;
    string s;
    for (int i = 0; i < N; ++i) s += (char)('A' + i);
    for (int i = 0; i < N; ++i) for (int j = 0; j < N-1; ++j) {
        cout << "? " << s[j] << ' ' << s[j+1] << '\n';
        char ans; cin >> ans;
        if (ans == '>') swap(s[j], s[j+1]);
    }
    cout << "! " << s << '\n';
    return 0;
}
