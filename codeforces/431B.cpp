#include <bits/stdc++.h>
#define PB push_back
using namespace std;
typedef long long ll;
typedef long double ld;

int M[10][10];
int main(void) {
    // freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(nullptr);
    for (int i = 1; i <= 5; ++i)
        for (int j = 1; j <= 5; ++j)
            cin >> M[i][j];
    vector<int> arr {1,2,3,4,5};
    ll res = 0;
    do {
        ll sum = 0;
        for (int i = 0; i < 5; ++i) {
            for (int j = 0; i+j+1 < 5; j += 2) {
                sum += M[arr[i+j]][arr[i+j+1]];
                sum += M[arr[i+j+1]][arr[i+j]];
            }
        }
        res = max(res, sum);
    } while (next_permutation(arr.begin(), arr.end()));
    cout << res << endl;
    return 0;
}
