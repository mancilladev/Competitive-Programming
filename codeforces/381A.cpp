#include <bits/stdc++.h>
#define PB push_back
using namespace std;
typedef long long ll;
typedef long double ld;
const ll INF = ll(1e18);

int main(void) {
    // freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(nullptr);
    int n; cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    int l = 0, r = n - 1;
    int score[2] {0};
    int x = 0;
    while (l <= r) {
        score[x] += max(arr[l], arr[r]);
        if (arr[l] > arr[r])
            ++l;
        else
            --r;
        x = (x+1)%2;
    }
    cout << score[0] << ' ' << score[1] << endl;

    return 0;
}
