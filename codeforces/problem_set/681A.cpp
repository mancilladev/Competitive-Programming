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
    bool res = 0;
    for (int i = 0; i < N; ++i) {
        string s;
        int prev, cur;
        cin >> s >> prev >> cur;
        if (prev >= 2400 && prev < cur)
            res = 1;
    }

    cout << (res ? "YES" : "NO") << endl;

    return 0;
}
