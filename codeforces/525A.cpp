#include <bits/stdc++.h>
#define PB push_back
using namespace std;
typedef long long ll;
typedef long double ld;

int main(void) {
    // freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(nullptr);
    int n; cin >> n;
    int ans = 0;
    int key[1000] {0};
    for (int i = 1; i <= (n<<1)-2; ++i) {
        char c; cin >> c;
        if ('a' <= c && c <= 'z')
            key[c - 'a']++;
        else {
            c = tolower(c);
            if (key[c - 'a'] == 0) ans++;
            else key[c - 'a']--;
        }
    }
    cout << ans << endl;
    return 0;
}

