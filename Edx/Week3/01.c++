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

void mergeSort(vector<int>* v, vector<int>* w, int l, int r) {
    if (l+1 >= r) return;

    int m = (r+l)/2;
    mergeSort(v, w, l, m);
    mergeSort(v, w, m, r);

    int i, j, k;
    i = l; j = m; k = l;
    while (i < m || j < r) {
        if (j == r || (i < m && v->at(i) <= v->at(j)))
            w->at(k++) = v->at(i++);
        else
            w->at(k++) = v->at(j++);
    }

    for (int i = l; i < r; i++)
        v->at(i) = w->at(i);

    cout << l+1 << ' ' << r << ' ' << v->at(l) << ' ' << v->at(r-1) << '\n';
}

int main() {
    int n; cin >> n;
    vector<int> v(n), w(n);

    for (int i = 0; i < n; i++)
        cin >> v[i];

    mergeSort(&v, &w, 0, v.size());

    for (auto x: v)
        cout << x << ' ';
    cout << '\n';

    return 0;
}
