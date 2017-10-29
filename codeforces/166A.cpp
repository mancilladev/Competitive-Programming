#include <bits/stdc++.h>
#define PB push_back
using namespace std;
typedef long long ll;
typedef long double ld;

int N, K;
int main(void) {
    // freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(nullptr);
    cin >> N >> K;
    vector<pair<int, int> > v;
    for (int i = 0; i < N; ++i) {
        int a, b; cin >> a >> b;
        v.PB({-a, b});
    }
    sort(begin(v), end(v));
    pair<int,int> target = v[K - 1];
    auto l = lower_bound(begin(v), end(v), target);
    auto r = upper_bound(begin(v), end(v), target);
    cout << distance(l, r) << endl;
    return 0;
}
