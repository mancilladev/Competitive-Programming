#include <bits/stdc++.h>
#define PB push_back
using namespace std;
typedef long long ll;
typedef long double ld;

int N, arr[1007];

void f(int n) {
    if (n == 1) return;
    f(n - 1);
    int tmp = arr[n-1];
    arr[n-1] = arr[n];
    arr[n] = tmp;
}

int main(void) {
    // freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(nullptr);
    cin >> N;
    for (int i = 1; i <= N; ++i)
        arr[i] = i;
    for (int i = 1; i < N; ++i)
        f(N);
    for (int i = 1; i <= N; ++i)
        cout << arr[i] << ' ';
    cout << endl;
    return 0;
}
