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

string s;
int main(void) {
    ios_base::sync_with_stdio(0), cin.tie(nullptr);
    while (cin >> s) {
        if (s == "0") break;
        int n = 0;
        for (auto c: s) n += c - '0';
        while (n > 9) {
            int nn = 0;
            while (n) nn += n%10, n /= 10;
            n = nn;
        }
        cout << n << endl;
    }
    return 0;
}
