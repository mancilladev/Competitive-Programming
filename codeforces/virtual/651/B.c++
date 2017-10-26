#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> v(1001, 0);

    int tmp;
    for (int i = 0; i < n; ++i)
        cin >> tmp, v[tmp]++;

    int ans = 0;
    while (n > 0) {
        int arrsize = 0;
        for (int i = 0; i < v.size(); i++)
            if (v[i]) arrsize++, v[i]--, n--;
        ans += arrsize-1;
    }
    cout << ans << '\n';

    return 0;
}
