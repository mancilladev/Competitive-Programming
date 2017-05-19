#ifdef JUDGE
#include <fstream>
std::ifstream cin("input.txt");
std::ofstream cout("output.txt");
#else
#include <iostream>
using std::cin;
using std::cout;
#endif
#include <vector>
using namespace std;

unsigned long long cnt;

void mergeSort(vector<int>* v, vector<int>* w, int l, int r) {
    if (l + 1 >= r) return;

    int m = (l+r)/2;
    mergeSort(v, w, l, m);
    mergeSort(v, w, m, r);

    int i, j, k;
    i = k = l;
    j = m;
    while (i < m || j < r) {
        if (j == r || (i < m && v->at(i) <= v->at(j)))
            w->at(k++) = v->at(i++);
        else {
            if (v->at(i) > v->at(j))
                cnt += (m - i);
            w->at(k++) = v->at(j++);
        }
    }

    for (i = l; i < r; i++)
        v->at(i) = w->at(i);
}

int main() {
    int n; cin >> n;

    cnt = 0;
    vector<int> v(n), w(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    mergeSort(&v, &w, 0, n);

    cout << cnt << '\n';

    return 0;
}
