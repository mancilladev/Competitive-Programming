#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define PB push_back
#define MP make_pair
typedef long long ll;
typedef long double ld;
const ll INF = ll(1e18);
int N;

bool isSorted(auto& a) {
    for (int i = 0; i < N-1; ++i)
        if (a[i] >= a[i+1])
            return false;
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> N;
    vector<int> arr(N);
    for (int i = 0; i < N; ++i)
        cin >> arr[i];

    int p1=-1, p2;
    for (int i = 0; i < N-1; ++i) {
        if (arr[i] == arr[i+1]) break;
        if (arr[i] > arr[i+1]) {
            p1 = p2 = i+1;
            while (p2 < N && arr[p2-1] > arr[p2])
                ++p2;
            sort(arr.begin()+i, arr.begin()+p2);
            break;
        }
    }

    if (isSorted(arr)) {
        cout << "yes\n";
        if (p1 == -1)
            cout << "1 1" << '\n';
        else
            cout << p1 << ' ' << p2 << '\n';
    }
    else cout << "no\n";

    return 0;
}
