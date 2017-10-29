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
    vector<ll> arr(N);
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
        while (arr[i]%2 == 0) arr[i] /= 2;
        while (arr[i]%3 == 0) arr[i] /= 3;
    }
    bool res = 1;
    for (int i = 1; i < N; ++i)
        if (arr[i] != arr[0])
            res = 0;
    cout << (res ? "YES" : "NO") << '\n';

    return 0;
}
