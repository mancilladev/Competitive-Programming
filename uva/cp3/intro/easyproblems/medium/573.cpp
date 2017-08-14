#include <bits/stdc++.h>
using namespace std;

int main () {
    std::setprecision(2);
    double H, U, D, F;

    while (cin >> H >> U >> D >> F, H) {
        int day = 0;
        double curH = 0, fatigue = (U * F/100);

        while (curH >= 0) {
            day++;
            curH += max(U, 0.0);
            if (curH > H)
                break;
            curH -= D;
            U -= fatigue;
        }

        cout << (curH > H ? "success" : "failure") << " on day " << day << '\n';
    }
}
