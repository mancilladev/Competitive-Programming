#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N, b;
int main () {
    while (cin >> N >> b) {
        string path = "";
        int tmp = pow(2, N) - b;
        int lvl = 0;
        while (tmp >>= 1) ++lvl;
        for (int i = lvl+1; i < N; ++i)
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
