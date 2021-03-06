#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef pair<int,int> pii;
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define error(x) cerr << #x << " = " << x << endl
#define sz(x) (int)(x).size()
#define eb emplace_back
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

const int INF = 1e9 + 7;

string a, b;
int main(void) {
    ios_base::sync_with_stdio(0), cin.tie(nullptr);
    cin >> a >> b;
    while (sz(a) < sz(b)) a = "0" + a;
    while (sz(a) > sz(b)) b = "0" + b;
    for (int i = 0; i < sz(a); ++i) {
        if (a[i] > b[i]) return cout << "GREATER\n", 0;
        if (a[i] < b[i]) return cout << "LESS\n", 0;
    }
    cout << "EQUAL\n";
    return 0;
}
