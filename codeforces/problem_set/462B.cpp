#include <bits/stdc++.h>
#define PB push_back
using namespace std;
typedef long long ll;
typedef long double ld;

char c;
int N, K;
unordered_map<char, int> h;
int main(void) {
    // freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(nullptr);
    cin >> N >> K;
    for (int i = 0; i < N; ++i) {
        cin >> c;
        h[c]++;
    }
    vector<int> cnt;
    for (auto p : h) cnt.PB(p.second);
    sort(cnt.begin(), cnt.end(), greater<int>());
    ll res = 0;
    for (auto x : cnt) {
        res += (ll)min(K, x) * min(K, x);
        K -= x;
        if (K < 0) break;
    }
    cout << res << endl;
    return 0;
}
