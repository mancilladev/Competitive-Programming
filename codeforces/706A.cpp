#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define PB push_back
#define MP make_pair
typedef long long ll;
const ll INF = ll(1e9);
int X, Y, N;

struct Taxi {
    double x;
    double y;
    double v;
} taxi;

double dist(Taxi t) {
    return sqrt(pow(t.x - X, 2) + pow(t.y - Y, 2))/t.v;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> X >> Y >> N;
    double res = INF;
    for (int i = 0; i < N; ++i) {
        double a, b, c;
        cin >> a >> b >> c;
        taxi = {a, b, c};
        res = min(res, dist(taxi));
    }
    cout << setprecision(15) << res << '\n';

    return 0;
}
