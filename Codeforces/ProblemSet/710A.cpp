#include <bits/stdc++.h>
using namespace std;
#define PB push_back
typedef long long ll;
typedef long double ld;
const ll INF = ll(1e18);
string s;

int countPositions() {
    int col = s[0] - 'a';
    int row = s[1] - '1';
    int y, x;
    int cnt = 0;
    for (int i = -1; i <= 1; ++i)
        for (int j = -1; j <= 1; ++j) {
            y = row+i;
            x = col+j;
            if (y >= 0 && y < 8 && x >= 0 && x < 8 && i|j)
                ++cnt;
        }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> s;
    cout << countPositions() << '\n';

    return 0;
}
