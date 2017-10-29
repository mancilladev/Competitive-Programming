#include <bits/stdc++.h>
#define PB push_back
using namespace std;
typedef long long ll;
typedef long double ld;

int main(void) {
    // freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(nullptr);
    string s; cin >> s;
    int i = 0;
    while (i < (int)s.length()) {
        if (s[i] == '.')
            s[i] = '0';
        else if (i + 1 < (int)s.length()) {
            if (s[i+1] == '-')
                s.replace(i, 2, "2");
            else
                s.replace(i, 2, "1");
        }
        i++;
    }
    cout << s << endl;
    return 0;
}
