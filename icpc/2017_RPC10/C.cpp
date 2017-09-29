#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N, b;
string path;
int main () {
    while (cin >> N >> b) {
        path = "";
        ll top = pow(2, N);
        int lvl = log2(top - b);
        for (int i = lvl+1; i < N; ++i)
            b -= pow(2, i);
        while (lvl--) {
            if (b&1) path = 'R' + path;
            else path = 'L' + path;
            b = (b+1)/2;
        }
        cout << path << endl;
    }
    return 0;
}
