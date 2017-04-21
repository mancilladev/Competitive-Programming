#include <bits/stdc++.h>
using namespace std;
#define PB push_back
typedef long long ll;
typedef long double ld;
const ll INF = ll(1e18);

ld calc(ld num, ld p) {
    return num * (1-p);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    ld time, down, owe, k, car, m, depr, payment;
    while (cin >> time >> down >> owe >> k, time >= 0) {
        vector<ld> month(time+1, INF);
        month[0] = 0;
        while (k--)
            cin >> m >> depr, month[m] = depr;
        for (int i = 1; i < month.size(); ++i)
            if (month[i] == INF) month[i] = month[i-1];

        m = 0;
        payment = owe / time;
        car = calc(owe+down, month[m]);
        while (owe >= car) {
            ++m;
            car = calc(car, month[m]);
            owe -= payment;
        }
        if (m == 1)
            cout << "1 month\n";
        else
            cout << m << " months\n";
    }

    return 0;
}
