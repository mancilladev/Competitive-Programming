#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define PB push_back
#define MP make_pair
typedef long long ll;
const ll INF = ll(1e18);
int N;

int calc(string s) {
    int cnt = 0;
    for (int i = 1; i < s.size(); ++i)
        if (s[i-1] == 'V' && s[i] == 'K') ++cnt;
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    string ss;
    cin >> ss;
    int res = calc(ss);
    for (int i = 0; i < ss.size(); ++i) {
        string stmp = ss;
        if (ss[i] == 'V') stmp[i] = 'K';
        else stmp[i] = 'V';
        res = max(res, calc(stmp));
    }
    cout << res << '\n';

    return 0;
}
