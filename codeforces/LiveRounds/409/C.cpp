#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define PB push_back
#define MP make_pair
typedef long long ll;
typedef long double ld;
const ll INF = ll(1e18);
ll N, P;

struct Dev {
    ld loss;
    ld power;
} ;

vector<Dev> arr;

ld calc(Dev d) {
    return d.power/d.loss;
}

bool f(ld time) {
    ld needsum = 0;
    for (int i = 0; i < N; ++i) {
        ld need = max(0.0L, (time - calc(arr[i])) * arr[i].loss);
        needsum += need;
    }
    ld supply = time * P;
    return supply >= needsum;
}

int main() {
    cin >> N >> P;
    ll sumD = 0;
    arr.resize(N);

    for (int i = 0; i < N; ++i) {
        ld loss, power;
        cin >> loss >> power;
        arr[i] = {loss, power};
        sumD += loss;
    }

    if (P >= sumD) {
        cout << "-1\n";
        return 0;
    }

    ld left = 0, right = INF;
    for (int i = 0; i < 220; ++i) {
        ld mid = (left + right)/2;
        if (f(mid)) left = mid;
        else right = mid;
    }

    printf("%.9f\n", (double)left);

    return 0;
}
