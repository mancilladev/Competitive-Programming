#include <bits/stdc++.h>
#define PB push_back
using namespace std;
typedef long long ll;
typedef long double ld;

int N, M, D;
int main(void) {
    // freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(nullptr);
    cin >> N >> M >> D;
    vector<int> arr(N*M);
    for (int i = 0; i < N*M; ++i) cin >> arr[i];
    sort(begin(arr), end(arr));
    int m = arr[N*M/2], res = 0;
    for (int i = 0; i < N*M; ++i) {
        if (abs(arr[i]-m)%D) return cout << -1 << endl, 0;
        else res += abs(arr[i]-m)/D;
    }
    cout << res << endl;
    return 0;
}
