#include <bits/stdc++.h>
#define PB push_back
using namespace std;
typedef long long ll;
typedef long double ld;

vector<string> M(4);

int check() {
    for (int i = 0; i+1 < 4; ++i)
        for (int j = 0; j+1 < 4; ++j) {
            int s = 0;
            s += M[i][j] == '#';
            s += M[i+1][j] == '#';
            s += M[i][j+1] == '#';
            s += M[i+1][j+1] == '#';
            if (s != 2) return 1;
        }
    return 0;
}

int main(void) {
    // freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(nullptr);
    for (int i = 0; i < 4; ++i)
        cin >> M[i];
    cout << (check() ? "YES" : "NO") << endl;
    return 0;
}
