#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

#define error(x) cerr << #x << " = " << x << endl
#define sz(x) (int)(x).size()
#define eb emplace_back
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

const int MOD = 1e9 + 7;

string s;

int solves(string sub) {
    int x = 0;
    for (int i = 0; i < sz(s); ++i) {
        if (s[i] == sub[x]) ++x;
        if (x == sz(sub)) return 1;
    }
    return 0;
}
int main(void) {
    // freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(nullptr);
    cin >> s;
    for (int i = 0; i < 1000; i += 8) {
        string sub = to_string(i);
        if (solves(sub))
            return cout << "YES\n" << sub << '\n', 0;
    }
    cout << "NO\n";
    return 0;
}
