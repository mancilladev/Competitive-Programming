#include <bits/stdc++.h>
#define PB push_back
using namespace std;
typedef long long ll;
typedef long double ld;

int N, M;
int main(void) {
    // freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(nullptr);
    cin >> N;
    vector<ll> v(N+1);
    for (int i = 1; i <= N; ++i) cin >> v[i];
    vector<ll> u = v;
    sort(begin(u), end(u));
    for (int i = 1; i <= N; ++i) v[i] += v[i-1], u[i] += u[i-1];
    cin >> M;
    for (int i = 1; i <= M; ++i) {
        int l, r, t; cin >> t >> l >> r;
        if (t == 1) cout << v[r] - v[l-1] << endl;
        else cout << u[r] - u[l-1] << endl;
    }
    return 0;
}
