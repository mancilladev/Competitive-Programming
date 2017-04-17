#include <iostream>
#include <vector>
#include <algorithm>
#define INF 0x3f3f3f3f
using namespace std;

int main () {
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];
    sort(v.begin(), v.end());
    
    int mind = INF;
    for (int i = 1; i < n; ++i) {
        int d = abs(v[i] - v[i-1]);
        if (mind > d)
            mind = d;
    }

    int cnt = 0;
    for (int i = 1; i < n; ++i)
        if (abs(v[i] - v[i-1]) == mind)
            ++cnt;
    
    cout << mind << ' ' << cnt << '\n';

    return 0;
}
