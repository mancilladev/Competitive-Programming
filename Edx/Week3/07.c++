#ifdef JUDGE
#include <fstream>
std::ifstream cin("input.txt");
std::ofstream cout("output.txt");
#else
#include <iostream>
#endif
#include <tuple>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, k; cin >> n >> k;
    vector< tuple<int, int, int> > S(n);

    for (int i = 0; i < n; ++i) {
        int v, w;
        cin >> v >> w;
        S[i] = make_tuple(v, w, i+1);
    }

    partial_sort(S.begin(), S.begin()+k, S.end(), [](auto &t1, auto &t2) {
        int v1, w1, v2, w2, _;
        tie(v1, w1, _) = t1;
        tie(v2, w2, _) = t2;
        return w1 < w2;
    });

    sort(S.begin()+k, S.end(), [](auto &t1, auto &t2) {
        int v1, w1, v2, w2, _;
        tie(v1, w1, _) = t1;
        tie(v2, w2, _) = t2;
        return v1 > v2;
    });

    int i = 0, j = k;
    double top = 0, bot = 0;
    while (k--) {
        int v1, w1, v2, w2, p1, p2;
        tie(v1, w1, p1) = S[i];
        tie(v2, w2, p2) = S[j];
        double newval1 = (top+v1)/(bot+w1);
        double newval2 = (top+v2)/(bot+w2);
        if (j >= n || newval1 > newval2) {
            top += v1;
            bot += w1;
            cout << p1 << ' ';
            ++i;
        }
        else {
            top += v2;
            bot += w2;
            cout << p2 << ' ';
            ++j;
        }
    }
    cout << '\n';

    return 0;
}
