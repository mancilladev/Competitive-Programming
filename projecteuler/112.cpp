#include <bits/stdc++.h>
using namespace std;

int isDec(int n) {
    int last = -1;
    while (n) {
        if (last > n%10)
            return 0;
        last = n % 10;
        n /= 10;
    }
    return 1;
}

int isInc(int n) {
    int last = 10;
    while (n) {
        if (last < n%10)
            return 0;
        last = n % 10;
        n /= 10;
    }
    return 1;
}

int isBouncy(int n) {
    return (!isInc(n) && !isDec(n));
}

int main () {
    int bouncy_cnt = 0;
    int cnt = 1;

    while (bouncy_cnt*100/cnt < 99) {
        if (isBouncy(++cnt))
            bouncy_cnt++;
    }

    cout << cnt << endl;

    return 0;
}
