#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAX = 1e5 + 7;
int N, K;
ll arr[MAX];
int main () {
    while (cin >> N >> K) {
        ll low = 0, high = 0;
        for (int i = 0; i < N; ++i) {
            cin >> arr[i];
            low = max(low, arr[i]);
            high += arr[i];
        }

        while (low <= high) {
            ll mid = (low+high)/2;
            ll sum = 0;
            int parts = 1;
            for (int i = 0; i < N; ++i) {
                if (sum + arr[i] > mid) {
                    sum = arr[i];
                    ++parts;
                } else {
                    sum += arr[i];
                }
            }
            if (parts > K) low = mid + 1;
            else high = mid - 1;
        }
        cout << low << '\n';
    }
    return 0;
}
