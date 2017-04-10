#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int N, M, K;
    cin >> N >> M >> K;
    --M;
    vector<int> v(N);
    for (int i = 0; i < N; ++i) {
        cin >> v[i];
    }

    int i = 0;

    while (true) {
        if (M+i < N && (v[M+i] > 0 && v[M+i] <= K))
            break;
        if (M-i >= 0 && (v[M-i] > 0 && v[M-i] <= K))
            break;
        ++i;
    }

    cout << i*10 << '\n';

    return 0;
}
