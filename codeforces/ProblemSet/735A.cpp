#include <bits/stdc++.h>
using namespace std;
#define PB push_back
typedef long long ll;
typedef long double ld;
const ll INF = ll(1e18);
int N, K, g, t;
string s;

bool solves() {
    int l = min(t,g);
    int r = max(t,g);
    while (l < r && s[l] != '#')
        l += K;
    return l == r;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> N >> K;
    cin >> s;
    for (int i = 0; i < N; ++i) {
        if (s[i] == 'G')
            g = i;
        if (s[i] == 'T')
            t = i;
    }

    if (solves())
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}
