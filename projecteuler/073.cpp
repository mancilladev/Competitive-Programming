#include <bits/stdc++.h>
using namespace std;
#define PB push_back
typedef long long ll;
typedef long double ld;
const ll INF = ll(1e18);
const int MAX = (1e5);
int N, arr[MAX] {0};

int gcd(int a, int b) {
    if (a % b == 0)
        return b;
    return gcd(b, a % b);
}

int main() {
    int limit = 12000;
    int result = 0;

    for (int d = 5; d <= limit; d++) {
        int l = d/3 + 1;
        int r = (d-1)/2 + 1;
        for (int n = l; n < r; n++)
            if (gcd(n, d) == 1) result++;
    }

    cout << result << endl;

    return 0;
}
