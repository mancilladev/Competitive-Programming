#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define PB push_back
#define MP make_pair
typedef long long ll;
typedef long double ld;
const ll INF = ll(1e18);
string alpha = "abcdefghijklmnopqrstuvwxyz";
string s;

int dist(char cur, char obj) {
    int pos = cur - 'a';

    int r = pos;
    int cnt1 = 0;
    while (alpha[r] != obj)
        r = (r+1)%alpha.size(), ++cnt1;

    int l = pos;
    int cnt2 = 0;
    while (alpha[l] != obj) {
        --l;
        if (l < 0)
            l = alpha.size()-1;
        ++cnt2;
    }

    return min(cnt1, cnt2);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> s;
    int res = dist('a', s[0]);
    for (int i = 1; i < s.size(); ++i)
        res += dist(s[i-1], s[i]);
    cout << res << '\n';

    return 0;
}
