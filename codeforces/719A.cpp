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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<int> arr(N);
    for (int i = 0; i < N; ++i)
        cin >> arr[i];

    if (arr[N-1] == 15)
        cout << "DOWN";
    else if (arr[N-1] == 0)
        cout << "UP";
    else if (N == 1)
        cout << "-1";
    else if (arr[N-2] > arr[N-1])
        cout << "DOWN";
    else
        cout << "UP";
    cout << '\n';

    return 0;
}
