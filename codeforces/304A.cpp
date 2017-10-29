#include <bits/stdc++.h>
#define PB push_back
using namespace std;
typedef long long ll;
typedef long double ld;

int N;
int main(void) {
    // freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(nullptr);
    cin >> N;
    int res = 0;
    for (ll a = 1; a < N; ++a)
        for (ll b = a; a*a + b*b <= N*N; ++b) {
            ld c = sqrt(a*a + b*b);
            if (c == (ll)c) ++res;
        }
    cout << res << endl;
    return 0;
}
