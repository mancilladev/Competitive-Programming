#include <iostream>
#include <vector>
using namespace std;

int main () {
    int n, k; cin >> n >> k;
    vector<int> v(n), a(k);
    for (int i = 0; i < n; ++i)
        v[i] = i+1;
    for (int i = 0; i < k; ++i)
        cin >> a[i];

    int cur = 0;
    for (int i = 0; i < k; ++i) {
        int kill = (a[i] + cur)%(v.size());
        cout << v[kill] << ' ';
        v.erase(v.begin() + kill);
        cur = kill;
    }
    cout << endl;

    return 0;
}
