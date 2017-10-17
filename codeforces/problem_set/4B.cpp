#include <bits/stdc++.h>
using namespace std;
#define error(x) cerr << #x << " = " << x << endl;
#define mt make_tuple
#define eb emplace_back
#define pb push_back
typedef long long ll;
typedef long double ld;

int main(void) {
    // freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(nullptr);
    int d, sum; cin >> d >> sum;
    int l = 0, r = 0;
    vector<int> res, unused;
    for (int i = 0; i < d; ++i) {
        int a, b; cin >> a >> b;
        l += a; r += b;
        res.pb(a);
        unused.pb(b);
    }
    if (sum < l || r < sum)
        return cout << "NO\n", 0;

    cout << "YES\n";
    int i = 0;
    while (l < sum) {
        int diff = unused[i] - res[i];
        int n = min(diff, sum - l);
        l += n;
        res[i] += n;
        ++i;
    }
    for (auto x : res) cout << x << ' ';
    cout << '\n';
    return 0;
}
