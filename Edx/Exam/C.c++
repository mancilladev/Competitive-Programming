#ifdef JUDGE
#include <fstream>
std::ifstream cin("input.txt");
std::ofstream cout("output.txt");
#else
#include <iostream>
#endif
#include <vector>
#include <algorithm>
using namespace std;
long long N, M;

bool mergeSort(auto& v, auto& w, int l, int r) {
    if (l+1 < r) {
        int m = (l+r)/2;
        if (!mergeSort(v, w, l, m))
            return false;
        if (!mergeSort(v, w, m, r))
            return false;

        if (v[m-1] > v[r-1] && v[m-1] + v[r-1] > M)
            return false;
        if (v[m-1] > v[m] && v[m-1] + v[m] > M)
            return false;

        int i, j, k;
        i = l; j = m; k = l;
        while (i < m || j < r) {
            if (v[i] > M|| v[j] > M) return false;
            if (j == r || i < m && v[i] <= v[j])
                w[k++] = v[i++];
            else
                w[k++] = v[j++];
        }

        for (int i = l; i < r; ++i)
            v[i] = w[i];
    }
    return true;
}

int main() {
    cin >> N >> M;
    vector<long long> arr(N), w(N);
    for (int i = 0; i < N; ++i)
        cin >> arr[i];
    cout << (mergeSort(arr, w, 0, N) ? "Yes" : "No") << endl;

    return 0;
}
