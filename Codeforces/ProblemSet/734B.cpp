#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <utility>
using namespace std;
#define F first
#define S second
#define PB push_back
#define MP make_pair
typedef long long ll;
const ll INF = ll(1e18);

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    vector<int> arr(4);
    for (int i = 0; i < 4; ++i)
        cin >> arr[i];
    
    ll sum = 0;
    while (arr[0] && arr[2] && arr[3]) {
        arr[0]--;
        arr[2]--;
        arr[3]--;
        sum += 256;
    }

    while (arr[0] && arr[1]) {
        arr[0]--;
        arr[1]--;
        sum += 32;
    }

    cout << sum << '\n';

    return 0;
}
