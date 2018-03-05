#include <bits/stdc++.h>
using namespace std;

struct Pos {
    int x, y, z;
    bool operator == (const Pos& other) {
        return (other.x == x && other.y == y && other.z == z);
    }
    void move(const Pos& other, const Pos& foe) {
        if (*this == other) return;

        int f[3] {x, y, z};
        int g[3] {other.x, other.y, other.z};
        vector<int> positions = {0,1,2};
        random_shuffle(begin(positions), end(positions));

        for (auto i : positions) {
            if (f[i] != g[i]) {
                int d = (g[i] - f[i]);
                f[i] += ((d > 0) - (d < 0));
                if (f[0] == foe.x && f[1] == foe.y && f[2] == foe.z) {
                    f[i] -= ((d > 0) - (d < 0));
                } else {
                    break;
                }
            }
        }
        tie(x, y, z) = {f[0], f[1], f[2]};
    }
} a, b, at, bt;

ostream& operator <<(ostream& os, const Pos& p) {
    return os << "(" << p.x << ", " << p.y << ", " << p.z << ")";
}

int main(void) {
    cin >> a.x >> a.y >> a.z >> at.x >> at.y >> at.z;
    cin >> b.x >> b.y >> b.z >> bt.x >> bt.y >> bt.z;

    cout << a << ' ' << b << '\n';
    while (!(a == at && b == bt)) {
        a.move(at, b);
        b.move(bt, a);
        cout << a << ' ' << b << '\n';
    }
    return 0;
}
