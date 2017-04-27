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
    if (N%2 != 0)
        cout << "-1" << '\n';
    else {
        for (int i = 1; i <= N; ++i) {
            if (i%2 != 0)
                cout << i+1;
            else
                cout << i-1;
            cout << ' ';
        }
        cout << '\n';
    }


    return 0;
}
