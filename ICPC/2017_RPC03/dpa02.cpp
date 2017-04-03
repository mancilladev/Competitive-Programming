#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    
    while (t--) {
        unsigned long long n; cin >> n;
        unsigned long long sum = 1;

        for (long long i = 2; i <= sqrt(n); ++i) {
            if (n%i == 0) {
                if (i == n/i)
                    sum += i;
                else
                    sum += i + n/i;
            }
        }

        if (sum > n) cout << "abundant\n";
        else if (sum < n) cout << "deficient\n";
        else cout << "perfect\n";
    }

    return 0;
}
