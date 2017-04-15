#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <cmath>
#include <unordered_map>
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

    int N, M; cin >> N >> M;
    unordered_map<string, string> table;
    for (int i = 0; i < M; ++i) {
        string a, b; cin >> a >> b;
        table[a] = (a.size() > b.size()) ? b : a;
    }

    string s;
    while (cin >> s)
        cout << table[s] << ' ';
    cout << '\n';

    return 0;
}
