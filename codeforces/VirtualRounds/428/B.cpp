#include <bits/stdc++.h>
using namespace std;

int n, k, cnt[5], seats[5];
int main(void) {
    cin >> n >> k;
    seats[2] = 2 * n, seats[4] = n;

    for (int i = 0; i < k; ++i) {
        int x; cin >> x;
        while (x >= 3) {
            if (seats[4] > 0)
                seats[4]--, x -= 4;
            else if (seats[2] > 0)
                seats[2]--, x -= 2;
            else
                return cout << "NO" << endl, 0;
        }
        if (x > 0)
            cnt[x]++;
    }

    while (cnt[2]) {
        if (seats[2] > 0)
            cnt[2]--, seats[2]--;
        else if (seats[4] > 0)
            cnt[2]--, seats[4]--, seats[1]++;
        else
            cnt[2]--, cnt[1] += 2;
    }

    if (cnt[1] > seats[1] + seats[2] + seats[4] * 2) puts("NO");
    else puts("YES");

    return 0;
}
