#include <bits/stdc++.h>
using namespace std;

int main(void) {
    char c;
    int t1[3], t[3];
    cin >> t1[0] >> c >> t1[1] >> c >> t1[2];
    cin >> t2[0] >> c >> t2[1] >> c >> t2[2];

    for (int i = 0; i < 3; ++i) t1[i] -= t2[i];

    if (t1[2] < 60) t1[2] += 60, --t1[1];
    if (t1[1] < 60) t1[1] += 60, --t1[0];
    if (t1[0] < 0) t1[0] += 24;

    if (t1[0] + t1[1] + t1[2] == 0) t1[0] += 24;

    return 0;
}
