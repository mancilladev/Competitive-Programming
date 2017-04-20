#ifdef JUDGE
#include <fstream>
std::ifstream cin("input.txt");
std::ofstream cout("output.txt");
#else
#include <iostream>
#endif
#include <vector>
using namespace std;
const int MAX = 101;
int N, buf, pos[MAX], arr[MAX];

int main() {
    cin >> N;
    for (int i = 1; i <= N; ++i)
        cin >> arr[i], pos[arr[i]] = i;

    vector<pair<int, int> > res;
    for (int i = N; i > 1; --i) {
        while (arr[i] != i) {
            int p = pos[arr[i]+1];
            res.push_back({pos[arr[i]+1], pos[arr[i]]});

            // swap pos registry
            buf = pos[arr[i]+1];
            pos[arr[i]+1] = pos[arr[i]];
            pos[arr[i]] = buf;

            // swap arr vals
            buf = arr[i];
            arr[i] = arr[p];
            arr[p] = buf;
        }
    }

    cout << res.size() << '\n';
    for (auto pp: res)
        cout << pp.first << ' ' << pp.second << '\n';

    return 0;
}
