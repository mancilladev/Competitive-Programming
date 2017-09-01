#include <bits/stdc++.h>
#define PB push_back
using namespace std;
typedef long long ll;
typedef long double ld;
const ll INF = ll(1e18);

int main(void) {
    // freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(nullptr);
    int k;
    cin >> k;
    if (k == 0) {
        puts("a");
        return 0;
    }
    int cur = 0;
    while (k != 0) {
        int i;
        for (i = 1; ; ++i)
            if (i * (i + 1) / 2 > k) break;
        k -= i * (i - 1) / 2;
        while (i--)
            printf("%c", 'a'+cur);
        ++cur;
    }
    printf("\n");

    return 0;
}
