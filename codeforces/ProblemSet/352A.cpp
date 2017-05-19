#include <bits/stdc++.h>
using namespace std;
#define PB push_back
typedef long long ll;
typedef long double ld;
const ll INF = ll(1e18);
const int MAX = (1e5);
int N, arr[MAX] {0}, cnt[10] {0};

string formNumber() {
    string s = "";
    while (cnt[5]--)
        s += '5';
    while (cnt[0]--)
        s += '0';
    return s;
}

string solution() {
    int sum = 0;
    for (int i = 0; i < N; ++i) {
        ++cnt[arr[i]];
        sum += arr[i];
    }
    if (cnt[0] == 0)
        return "-1";
    while (cnt[5]) {
        if (sum%9 == 0)
            return formNumber();
        sum -= 5;
        cnt[5]--;
    }
    return "0";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> arr[i];

    cout << solution() << '\n';

    return 0;
}
