#include <bits/stdc++.h>
using namespace std;
#define PB push_back
typedef long long ll;
typedef long double ld;
const ll INF = ll(1e18);
ll T, N;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    bool first = 1;
    while (cin >> N) {
        if (!first) cout << '\n';

        unordered_map<string, ld> money;
        vector<string> people(N);
        for (int i = 0; i < N; ++i)
            cin >> people[i];

        for (int i = 0; i < N; ++i) {
            string p;
            ld total;
            int receivers;
            cin >> p >> total >> receivers;
            int gift = total / receivers;

            money[p] -= total;
            money[p] += total - gift * receivers;
            string curguy;
            for (int j = 0; j < receivers; ++j)
                cin >> curguy, money[curguy] += gift;
        }

        for (string p: people)
            cout << p << ' ' << money[p] << '\n';
        first = 0;
    }

    return 0;
}
