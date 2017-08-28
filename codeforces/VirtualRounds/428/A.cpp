#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n, k;
    vector<int> a(200);

    cin >> n >> k;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    
    int day = 0;
    while (k > 0 && day < n) {
        k -= min(8, a[day]);
        a[day+1] += max(0, a[day]-8);
        ++day;
    }

    cout << (k <= 0 ? day : -1) << endl;

    return 0;
}
