#include <bits/stdc++.h>
using namespace std;
#define error(x) cerr << #x << " = " << x << endl;
#define mt make_tuple
#define eb emplace_back
#define pb push_back
typedef long long ll;
typedef long double ld;

int N, K, X;
int main(void) {
    // freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(nullptr);
    cin >> N >> K >> X;
    vector<int> arr(N);
    for (int i = 0; i < N; ++i) cin >> arr[i];
    ll res = 0;
    for (int i = N-1; i >= 0; --i) {
        if (K-- > 0) res += X;
        else res += arr[i];
    }
    cout << res << endl;
    return 0;
}
