#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <cmath>
#include <set>
using namespace std;

long long distDoc(auto p1, auto p2) {
    return abs(p2.first - p1.first) + abs(p2.second - p1.second);
}

long long distDan(auto p1, auto p2) {
    long long top = (p2.first - p1.first);
    long long bot = (p2.second - p1.second);
    return sqrt(top*top + bot*bot);
}

int main() {
    int n; cin >> n;
    vector< pair<int, int> > v(n);
    
    int x, y;
    for (int i = 0; i < n; ++i)
        cin >> x >> y, v[i] = {x, y};

    int ans = 0;
    for (int i = 0; i < n; ++i)
        for (int j = i+1; j < n; ++j) {
            if (distDoc(v[i], v[j]) == distDan(v[i], v[j]))
                ++ans;
        }
    cout << ans << '\n';

    return 0;
}
