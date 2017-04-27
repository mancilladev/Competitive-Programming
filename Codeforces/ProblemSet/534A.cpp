#include <bits/stdc++.h>
using namespace std;
#define PB push_back
typedef long long ll;
typedef long double ld;
const ll INF = ll(1e18);

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int N;
    cin >> N;
    deque<int> arr;
    for (int i = 1; i <= N; i += 2)
        arr.PB(i);
    N = (N%2 == 0 ? N : N-1);
    for (int i = N; i >= 2; i -= 2) {
        if (abs(arr.back()-i) > 1)
            arr.PB(i);
        else if (abs(arr.front()-i) > 1)
            arr.push_front(i);
    }

    cout << arr.size() << '\n';
    for (int x: arr)
        cout << x << ' ';
    cout << endl;

    return 0;
}
