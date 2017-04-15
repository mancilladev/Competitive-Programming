#include <iostream>
#include <cmath>
using namespace std;
#define F first
#define S second
#define PB push_back
#define MP make_pair
typedef long long ll;
const ll INF = ll(1e18);

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int N; cin >> N;

    int res;
    res = pow(8, (N-1)%4+1);

    cout << res%10 << '\n';

    return 0;
}
