#include <bits/stdc++.h>
using namespace std;
#define PB push_back
typedef long long ll;
typedef long double ld;
const ll INF = ll(1e18);
int N, K;
string s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> N >> K;
    vector<string> arr(N);
    for (int i = 0; i < N; ++i)
        cin >> arr[i];
    cin >> s;

    int best = 0, worst;
    int cnt = 0;
    for (string cur: arr) {
        if (cur.size() == s.size())
            ++cnt;
        if (cur.size() < s.size())
            ++best;
    }

    int extra = best%K;
    best += best/K * 5;
    worst = best;
    ++best;
    worst += cnt + (cnt+extra-1)/K*5;
    cout << best << ' ' << worst << '\n';

    return 0;
}
