#include <bits/stdc++.h>
using namespace std;
#define PB push_back
typedef long long ll;
typedef long double ld;
const ll INF = ll(1e18);
ll a, b;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> a >> b;
    vector<int> arr(3, 0);
    for (int i = 1; i <= 6; ++i) {
        int d1 = abs(a-i);
        int d2 = abs(b-i);
        if (d1 < d2)
            ++arr[0];
        else if (d1 == d2)
            ++arr[1];
        else
            ++arr[2];
    }

    for (auto x: arr)
        cout << x << ' ';
    cout << endl;

    return 0;
}
