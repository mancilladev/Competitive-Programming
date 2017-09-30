#include <bits/stdc++.h>
#define PB push_back
using namespace std;
typedef long long ll;
typedef long double ld;

int n;
vector<int> arr;
int main(void) {
    ios_base::sync_with_stdio(0), cin.tie(nullptr);
    cin >> n;
    for (int i = 0, x; i < n; ++i) {
        cin >> x;
        if (arr.size() == 0 || arr.back() != x)
            arr.push_back(x);
    }
    int res = 0;
    for (int i = 1; i < (int)arr.size()-1; ++i) {
        if (arr[i-1] < arr[i] && arr[i] > arr[i+1])
            ++res;
    }
    if (arr.size() == 1)
        return cout << (arr[0] > 0) << endl, 0;
    if (arr[0] > arr[1])
        ++res;
    if (arr[arr.size()-1] > arr[arr.size()-2])
        ++res;
    cout << res << endl;
    return 0;
}
