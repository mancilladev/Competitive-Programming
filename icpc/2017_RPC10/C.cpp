#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N, b;
int main () {
    while (cin >> N >> b) {
        string path = "";
        ll top = pow(2, N);
        ll lvl = log2(top - b);
        for (ll i = lvl+1; i < N; ++i)
            b -= pow(2, i);
        while (lvl--) {
            if (b&1) path += 'R';
            else path += 'L';
            b = (b+1)/2;
        }
        reverse(path.begin(), path.end());
        cout << path << endl;
    }
    return 0;
}
