#include <bits/stdc++.h>
using namespace std;
#define PB push_back
typedef long long ll;
typedef long double ld;
const ll INF = ll(1e18);
ll T, N;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> T;
    while (T--) {
        cin >> N;
        vector<int> arr(N);
        int res = 0, prev;
        for (int i = 0; i < N; ++i) {
            string s;
            cin >> s;
            if (s[0] == 'L')
                arr[i] = -1;
            else if (s[0] == 'R')
                arr[i] = 1;
            else if (s[0] == 'S') {
                cin >> s;
                cin >> prev;
                arr[i] = arr[prev-1];
            }
            res += arr[i];
        }
        cout << res << '\n';
    }

    return 0;
}
