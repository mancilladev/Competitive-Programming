#include <bits/stdc++.h>
using namespace std;
#define PB push_back
typedef long long ll;
typedef long double ld;
const ll INF = ll(1e18);
const int MAX = (1e5);
int L, arr[MAX] {0};

bool change(char cur, char c1, char c2) {
    if (cur == 'x' && c1 == '-') return true;
    else if (cur == 'y' && c2 == 'y' && c1 == '+') return true;
    else if (cur == 'z' && c2 == 'z' && c1 == '+') return true;
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    while (cin >> L, L != 0) {
        --L;
        int sign = 1;
        char c = 'x';
        string s;

        for (int i = 0; i < L; ++i) {
            cin >> s;
            if (s == "No") continue;
            if (change(c, s[0], s[1])) sign = -sign;

            if (c == 'x') c = s[1];
            else if (c == 'y' && s[1] == 'y') c = 'x';
            else if (c == 'z' && s[1] == 'z') c = 'x';
        }

        cout << (sign == 1 ? '+' : '-') << c << '\n';
    }

    return 0;
}
