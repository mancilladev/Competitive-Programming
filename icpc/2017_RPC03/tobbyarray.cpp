#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, q;

    while (cin >> n >> q) {
        vector<int> original(n);
        for (int i = 0; i < n; ++i)
            cin >> original[i];

        for (int i = 0; i < q; ++i) {
            auto arr = original;
            int l, r, pos;
            cin >> l >> r >> pos;
            --l, --pos;

            nth_element(arr.begin()+l, arr.begin()+l+pos, arr.begin()+r);
            cout << arr[l+pos] << '\n';
        }
    }

    return 0;
}
