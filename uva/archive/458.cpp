#include <bits/stdc++.h>
using namespace std;
#define PB push_back
typedef long long ll;
typedef long double ld;
const ll INF = ll(1e18);
ll T, N;
string S;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    while (cin >> S) {
        for (int c = 0; c < S.size(); ++c)
            S[c] -= 7;
        cout << S << '\n';
    }

    return 0;
}
