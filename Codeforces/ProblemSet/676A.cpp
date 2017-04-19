#include <bits/stdc++.h>
using namespace std;
#define PB push_back
typedef long long ll;
typedef long double ld;
const ll INF = ll(1e18);
ll N, M;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> N;
    vector<ll> arr(N);
    int pmin, pmax;
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
        if (arr[i] == 1)
            pmin = i;
        if (arr[i] == N)
            pmax = i;
    }

    if (min(pmin, pmax) == 0 || max(pmin, pmax) == N-1)
        cout << N-1 << endl;
    else {
        int dl, dr;
        dl = min(pmin, pmax);
        dr = N - max(pmin, pmax) - 1;
        int min_dist = min(dl, dr);
        cout << N - min_dist - 1 << endl;
    }

    return 0;
}
