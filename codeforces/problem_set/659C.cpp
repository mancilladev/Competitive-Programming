#include <bits/stdc++.h>
#define PB push_back
using namespace std;
typedef long long ll;
typedef long double ld;

int n, m;
unordered_set<int> a;

int main(void) {
    // freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(nullptr);
    cin >> n >> m;
    vector<int> v;
    for (int x, i = 0; i < n; ++i) {
        cin >> x;
        a.insert(x);
    }
    for (int i = 1; i <= m; ++i)
        if (a.find(i) == a.end()) v.PB(i), m -= i;
    cout << v.size() << '\n';
    for (int x : v)
        cout << x << ' ';
    cout << endl;
    return 0;
}
