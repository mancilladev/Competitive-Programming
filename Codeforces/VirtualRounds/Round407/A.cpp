#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <utility>
#define F first
#define S second
#define PB push_back
#define MP make_pair
typedef long long ll;
using namespace std;
const ll INF = ll(1e18);

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int N, K; cin >> N >> K;
    vector<int> arr(N);
    for (int i = 0; i < N; ++i)
        cin >> arr[i];

    int res = 0;
    bool extra = false;
    for (int i = 0; i < N; ++i) {
        int cnt = arr[i]/K + (arr[i]%K ? 1 : 0);
        res += cnt/2;
        if (cnt%2 == 1) {
            if (!extra)
                ++res, extra = true;
            else
                extra = false;
        }
    }
    cout << res << '\n';

    return 0;
}
