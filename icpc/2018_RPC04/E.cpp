#include <bits/stdc++.h>
using namespace std;

int main (void) {
    int n; cin >> n;
    bool flag = false;
    while (n--) {
        int k, e;
        cin >> k >> e;
        if ((e & 1) && (k%4 == 3))
            flag = true;
    }
    cout << (flag ? "No." : "Yes.") << endl;
    return 0;
}
