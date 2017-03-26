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
    int n, k1, k2;
    int A, B, C, a1, a2;

    cin >> n >> k1 >> k2;
    cin >> A >> B >> C >> a1 >> a2;

    vector<int> v(n);
    v[0] = a1;
    v[1] = a2;

    for (int i = 2; i < n; i++) {
        int tmp = A * a1 + B * a2 + C;
        v[i] = tmp;
        a1 = a2;
        a2 = tmp;
    }

    if (k1 > n/2) {
        nth_element(v.begin(), v.begin()+k1-1, v.end());
        sort(v.begin()+k1-1, v.end());
    }
    else {
        nth_element(v.begin(), v.begin()+k2, v.end());
        sort(v.begin(), v.begin()+k2);
    }
    for (int i = k1-1; i < k2; i++)
        cout << v[i] << ' ';
    cout << '\n';

    return 0;
}
