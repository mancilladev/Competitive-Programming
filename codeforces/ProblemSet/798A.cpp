#include <bits/stdc++.h>
#define PB push_back
using namespace std;
typedef long long ll;
const ll INF = ll(1e18);

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    string s;
    cin >> s;
    int cnt = 0;
    int n = s.size();

    for (int i = 0; i < n/2; ++i)
        if (s[i] != s[n - i - 1]) ++cnt;

    if ((cnt <= 1 && (n&1)) || cnt == 1) puts("YES");
    else puts("NO");

    return 0;
}
