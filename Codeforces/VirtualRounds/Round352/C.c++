#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

struct point {
    int x;
    int y;
} A, B, C;

struct dp {
    double d;
    point p;
} ;

double distance(point a, point b) {
    double l = b.x - a.x;
    double r = b.y - a.y;
    return sqrt(l*l + r*r);
}

int main () {
    cin >> A.x >> A.y;
    cin >> B.x >> B.y;
    cin >> C.x >> C.y;

    int n; cin >> n;
    vector<dp> dA(n), dB(n), dC(n);
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        point p = {x, y};
        dA[i] = dp(), dA[i].d = distance(p, A), dA[i].p = p;
        dB[i] = dp(), dB[i].d = distance(p, B), dB[i].p = p;
        dC[i] = dp(), dC[i].d = distance(p, C), dC[i].p = p;
    }

    sort(dA.begin(), dA.end(), [](auto &left, auto &right) {
        return left.d < right.d;
    });
    sort(dB.begin(), dB.end(), [](auto &left, auto &right) {
        return left.d < right.d;
    });
    sort(dC.begin(), dC.end(), [](auto &left, auto &right) {
        return left.d < right.d;
    });

    int ci = 0;
    int min_dist = 0;
    bool used = false;
    for (int i = 0; i < n; i++) {
        if (!used && (A == C || B == C)) {
            while (find(used.begin(), used.end(), dC[ci].p) != used.end())
                ci++;
            double d1, d2;
            point cur = d[ci] 
            d1 = distance(A, C) + dA[ai].d;
            d2 = distance(dB[bi].p, C) + dB[bi].d;
            min_dist += dc[ci].d * 2;
            used.push_back(dc[ci].p);
            ci++;
        }
        else {
            double d1, d2;
            d1 = distance(dA[0].p, C) + dA[0].d;
            d2 = distance(dB[0].p, C) + dB[0].d;
            if (d1 < d2) {
                A = C;
                used.push_back(dA[0].p);
            }
            else {
                B = C;
                used.push_back(dB[0].p);
            }
            min_dist += min(d1, d2);
            used = true;
        }
    }

    for (auto x: dA)
        cout << x.d << ' ';
    cout << endl;
    for (auto x: dB)
        cout << x.d << ' ';
    cout << endl;

    cout << min_dist << endl;
    return 0;
}
