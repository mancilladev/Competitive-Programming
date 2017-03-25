#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, k1, k2;
    int A, B, C, a1, a2;
    vector<int> v;

    cin >> n >> k1 >> k2;
    cin >> A >> B >> C >> a1 >> a2;

    int i = 3, ai;
    while (i < k1) {
        ai = A * a1 + B * a2 + C;
        a1 = a2;
        a2 = ai;
        i++;
    }
    while (i <= k2) {
        ai = A * a1 + B * a2 + C;
        v.push_back(max(ai, a1));
        a1 = a2;
        a2 = ai;
        i++;
    }

    for (auto x: v)
        cout << x << ' ';
    cout << endl;

    return 0;
}
