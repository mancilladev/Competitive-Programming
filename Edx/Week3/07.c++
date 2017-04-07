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

struct Node {
    double v, w, pos;
} node;

bool operator <(const Node& x, const Node& y) {
    return x.v / x.w > y.v / y.w;
}

vector<Node> a, b;

long long add(long long s, Node node) {
    return s + node.v * node.w;
}

void mergeSort(int l, int r) {
    if (l + 1 >= r) return;

    int m = (l+r)/2;
    mergeSort(l, m);
    mergeSort(m, r);


    int i, j, k;
    i = k = l;
    j = m;

    long long s = add(0,a[0]);
    while (i < m || j < r) {
        if (j == r || (i < m && add(s,a[j]) > add(s,a[i])))
            s = add(s,a[i]), b[k++] = a[i++];
        else
            s = add(s,a[j]), b[k++] = a[j++];
    }

    for (int i = l; i < r; ++i)
        a[i] = b[i];
}

int main() {
    int n, k; cin >> n >> k;
    a.resize(n);
    b.resize(n);

    for (int i = 0; i < n; ++i)
        cin >> a[i].v >> a[i].w, a[i].pos = i+1;

    for (int i = 0; i < n; ++i) if (a[i] < a[0])
        node = a[0], a[0] = a[i], a[i] = node;

    mergeSort(1, n);

    for (int i = 0; i < k; ++i)
        cout << a[i].pos << ' ';
    cout << '\n';

    return 0;
}
