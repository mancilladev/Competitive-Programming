#include <algorithm>
#include <iostream>
#include <string>
#include <numeric>
#include <utility>
#include <vector>

using namespace std;

long long go_up(long long cur, long long root) {
    if (cur == root) {
        return cur;
    }
    long long mask = 1;
    while ((cur & mask) == 0) {
        mask <<= 1;
    }
    // 01, 11 -> 10
    cur ^= mask;
    cur |= mask << 1;
    return cur;
}

long long go_down(long long cur, char c) {
    if (cur % 2 == 1) {
        return cur;
    }
    long long mask = 1;
    while ((cur & mask) == 0) {
        mask <<= 1;
    }
    if (c == 'L') {
        cur ^= mask;
    }
    mask >>= 1;
    cur |= mask;
    return cur;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    int q;
    cin >> n >> q;
    long long root = (n + 1) / 2;
    for (; q > 0; --q) {
        long long cur;
        cin >> cur;
        string s;
        cin >> s;
        for (char c : s) {
            if (c == 'U') {
                cur = go_up(cur, root);
            } else {
                cur = go_down(cur, c);
            }
        }
        cout << cur << endl;
    }
    return 0;
}
