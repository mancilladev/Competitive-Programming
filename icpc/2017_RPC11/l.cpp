#include <bits/stdc++.h>
#define PB push_back
using namespace std;
typedef long long ll;
typedef long double ld;

int arr[4];
int main(void) {
    ios_base::sync_with_stdio(0), cin.tie(nullptr);
    for (int i = 0; i < 4; ++i)
        cin >> arr[i];

    int res = 0;
    if (arr[2] >= 2 && arr[0] >= 2) {
        int x = min(arr[2]/2, arr[0]/2);
        arr[0] -= 2 * x;
        arr[2] -= 2 * x;
        res += x;
    }
    if (arr[2] >= 1 && arr[0] >= 1 && arr[3] >= 2) {
        int x = min(arr[2], min(arr[0], arr[3]/2));
        arr[0] -= x;
        arr[2] -= x;
        arr[3] -= x * 2;
        res += x;
    }
    res += arr[0]/4;
    res += arr[1]/4;
    res += arr[3]/4;
    cout << res << endl;
    return 0;
}
