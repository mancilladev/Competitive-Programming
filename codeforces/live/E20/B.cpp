#include <bits/stdc++.h>
using namespace std;
#define PB push_back
typedef long long ll;
typedef long double ld;
const ll INF = ll(1e18);
const int MAX = 2*(1e5);
int N, arr[MAX+1] {0}, res[MAX+1] {0};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
        if (arr[i] != 0)
            res[i] = MAX;
    }
    for (int i = 1; i < N; ++i)
        res[i] = min(res[i], res[i-1]+1);
    for (int i = N-2; i >= 0; --i)
        res[i] = min(res[i], res[i+1]+1);

    for (int i = 0; i < N; ++i)
        cout << res[i] << ' ';
    cout << '\n';

    return 0;
}
