#include <bits/stdc++.h>
using namespace std;
#define PB push_back
typedef long long ll;
typedef long double ld;
const ll INF = ll(1e18);
ll T, N;

struct Site {
    string url;
    int rel;
} ;

bool operator >(const Site& x, const Site& y) {
    return x.rel > y.rel;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> T;
    for (int tt = 1; tt <= T; ++tt) {
        vector<Site> arr(10);
        for (int i = 0; i < 10; ++i)
            cin >> arr[i].url >> arr[i].rel;
        sort(arr.begin(), arr.end(), greater<Site>());
        cout << "Case #" << tt << ":\n";
        int j = 0;
        while (arr[j].rel == arr[0].rel)
            cout << arr[j++].url << '\n';
    }

    return 0;
}
