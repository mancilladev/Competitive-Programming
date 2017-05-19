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

int main() {
    int f, n; cin >> f >> n;
    vector<int> v(f+2);
    v[0] = 0;
    v[f+1] = n;
    for (int i = 0; i < f; ++i)
        cin >> v[i+1];

    sort(v.begin(), v.end());

    long long sum = 0;
    for (int i = 0; i <= f; ++i)
        sum += v[i+1] - v[i];
    sum /= f;

    int last = v[v.size()-1] - v[v.size()-2];
    if (v[v.size()-3-last] != v[v.size() - 2])
        cout << min(sum, (long long)v[1]) << '\n';
    else
        cout << "0\n";

    return 0;
}
