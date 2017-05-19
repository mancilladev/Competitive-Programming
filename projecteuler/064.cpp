#include <bits/stdc++.h>
using namespace std;
#define PB push_back
typedef long long ll;
typedef long double ld;
const ll INF = ll(1e18);
const int MAX = 10000;
int N, arr[MAX] {0};

int f(int n) {
    return n + (int)(1.0/2.0 + sqrt(n));
}

int main() {
    ifstream fin("file_064.txt");

    int N = 1;
    while (f(N+1) <= MAX)
        ++N;

    int a, b, res = 0;
    while (fin >> a >> b) {
        if (a > N)
            break;
        if (b%2)
            ++res;
    }

    cout << res << endl;

    return 0;
}
