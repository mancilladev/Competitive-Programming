#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define PB push_back
#define MP make_pair
typedef long long ll;
const ll INF = ll(1e18);
int N;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> N;
    ll res = 0;
    for (int i = 0; i < N; ++i) {
        string s;
        cin >> s;
        char c = s[0];
        if (c == 'I')
            res += 20;
        else if (c == 'D')
            res += 12;
        else if (c == 'O')
            res += 8;
        else if (c == 'C')
            res += 6;
        else if (c == 'T')
            res += 4;
    }
    cout << res << '\n';

    return 0;
}
