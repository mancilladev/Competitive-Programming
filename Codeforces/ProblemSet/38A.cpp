#include <bits/stdc++.h>
using namespace std;
#define PB push_back
typedef long long ll;
typedef long double ld;
const ll INF = ll(1e18);
int N, a, b, arr[101] {0};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> N;
    for (int i = 1; i < N; ++i) {
        cin >> arr[i];
        arr[i] += arr[i-1];
    }
    cin >> a >> b;
    cout << arr[b-1] - arr[a-1] << '\n';

    return 0;
}
