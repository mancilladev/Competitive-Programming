#include <bits/stdc++.h>
#define PB push_back
using namespace std;
typedef long long ll;
typedef long double ld;

int n, k;
int main(void) {
    // freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(nullptr);
    cin >> n >> k;
    --k;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    for (int i = k+1; i < n; ++i)
        if (arr[i] != arr[k])
            return cout << -1 << endl, 0;
    int res = k;
    while (res - 1 >= 0 && arr[res-1] == arr[k])
        --res;
    cout << res << endl;
    return 0;
}
