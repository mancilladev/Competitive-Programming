#include <bits/stdc++.h>
#define PB push_back
using namespace std;
typedef long long ll;
typedef long double ld;

int k;
string s;
int main(void) {
    // freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(nullptr);
    cin >> k >> s;
    string res, B;
    for (char c = 'a'; c <= 'z'; ++c) {
        int x = count(s.begin(), s.end(), c);
        if (x%k != 0) return cout << "-1\n", 0;
        for (int i = 0; i < x/k; ++i)
            B += c;
    }
    for (int i = 0; i < k; ++i)
        res += B;
    cout << res << endl;
    return 0;
}
