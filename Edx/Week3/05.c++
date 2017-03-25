#ifdef JUDGE
#include <fstream>
std::ifstream cin("input.txt");
std::ofstream cout("output.txt");
#else
#include <iostream>
using std::cin;
using std::cout;
#endif
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    int k;
    cin >> k;

    sort(v.begin(), v.end(), [](int a, int b){return a>b;});

    int t = 0;
    int tmp, i;
    while (true) {
        if (v[0] - t <= 0) break;
        v[0] = max(v[0]-(k-1), 0);
        t++;

        i = 1;
        while (i < n && v[i-1] < v[i]) {
            tmp = v[i-1];
            v[i-1] = v[i];
            v[i] = tmp;
            i++;
        }
    }

    cout << t << '\n';

    return 0;
}
