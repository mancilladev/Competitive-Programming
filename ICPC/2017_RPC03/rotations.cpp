#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;

    while (t--) {
        vector<bool> v(32, 0);

        unsigned int n; cin >> n;
        for (int i = 0; i < 32; ++i) {
            unsigned int cur = n & 31;
            v[cur] = 1;
            n = (n >> 1) | (n << 31);
        }

        bool ok = true;
        for (int i = 0; i < v.size(); ++i) {
            if (v[i] == 0) {
                cout << "no\n";
                ok = false;
                break;
            }
        }
        if (ok) cout << "yes\n";
    }

    return 0;
}
