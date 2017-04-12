#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <utility>
using namespace std;
#define F first
#define S second
#define PB push_back
#define MP make_pair
typedef long long ll;
const ll INF = ll(1e18);
const int MAX = (1e5);

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<int> arr;
    while (N-2 > 1) {
        arr.PB(2);
        N -= 2;
    }
    arr.PB(N);

    cout << arr.size() << '\n';
    for (int x: arr)
        cout << x << ' ';
    cout << '\n';

    return 0;
}
