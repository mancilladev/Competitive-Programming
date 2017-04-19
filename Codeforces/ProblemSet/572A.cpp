#include <bits/stdc++.h>
using namespace std;
#define PB push_back
typedef long long ll;
typedef long double ld;
const ll INF = ll(1e18);
ll N, M;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> N >> M;
    int x, y;
    cin >> x >> y;
    vector<ll> a(N), b(M);
    for (int i = 0; i < N; ++i)
        cin >> a[i];
    for (int i = 0; i < M; ++i)
        cin >> b[i];

    if (a[x-1] < b[M-y])
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}
