#include <bits/stdc++.h>
using namespace std;
#define PB push_back
typedef long long ll;
typedef long double ld;
const ll INF = ll(1e18);
const int MAX = (1e5) + 7;
ll N, M;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> N >> M;
    vector<ll> arr(N);
    for (int i = 0; i < N; ++i)
        cin >> arr[i];

    vector<bool> used(MAX, 0);
    vector<int> cnt(N);
    cnt[N-1] = 1;
    used[arr[N-1]] = 1;
    for (int i = N-2; i >= 0; --i) {
        cnt[i] = cnt[i+1] + (used[arr[i]] ? 0 : 1);
        used[arr[i]] = 1;
    }

    while (M--) {
        int req;
        cin >> req;
        cout << cnt[req-1] << '\n';
    }

    return 0;
}
