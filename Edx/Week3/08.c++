#ifdef JUDGE
#include <fstream>
std::ifstream cin("input.txt");
std::ofstream cout("output.txt");
#else
#include <iostream>
#endif
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, k; cin >> n >> k;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    vector<int> w = v;
    sort(w.begin(), w.end());

    bool impossible = false;
    for (int i = 0; i < n; i++) {
        bool found = false;

        int low = lower_bound(w.begin(), w.end(), v[i]) - w.begin();
        int up = upper_bound(w.begin(), w.end(), v[i]) - w.begin();
        low = low%k;
        up = --up%k;
        int pos = i%k;

        if (!((low <= pos && pos <= up) || (up < low && (pos <= up || low <= pos)))) {
            impossible = true;
            break;
        }
    }

    cout << (impossible ? "NO" : "YES") << endl;

    return 0;
}
