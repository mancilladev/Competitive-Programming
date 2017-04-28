#include <bits/stdc++.h>
using namespace std;
#define PB push_back
typedef long long ll;
typedef long double ld;
const ll INF = ll(1e18);
int N;

bool solves() {
    int y = 10000;
    for (int i = 0; i < N; ++i) {
        int t;
        string dir;
        cin >> t >> dir;
        char c = dir[0];
        if ((c == 'E' || c == 'W') && abs(y) == 10000)
            return false;
        if (c == 'N')
            y += t;
        else if (c == 'S')
            y -= t;
        if (abs(y) > 10000)
            return false;
    }
    return y == 10000;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> N;

    if (solves())
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}
