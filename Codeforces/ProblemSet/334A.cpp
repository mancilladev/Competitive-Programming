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

    cin >> N;
    vector<int> arr(N*N);
    for (int i = 1; i <= N*N; ++i)
        arr[i-1] = i;
    int l = 0, r = N*N-1;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N/2; ++j)
            cout << arr[l++] << ' ';
        for (int j = 0; j < N/2; ++j)
            cout << arr[r--] << ' ';
        cout << '\n';
    }

    return 0;
}

