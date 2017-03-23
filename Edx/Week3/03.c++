#ifdef JUDGE
#include <fstream>
std::ifstream cin("input.txt");
std::ofstream cout("output.txt");
#else
#include <iostream>
using std::cin;
using std::cout;
#endif
#include <deque>
using namespace std;

int main() {
    int n; cin >> n;
    deque<int> d = {1};

    int i = 3;
    while (d.size() < n) {
        if (d.size() == 1) {
            d.push_back(2);
            continue;
        }

        int middle = d.size()/2;
        int val = d[middle];
        d[middle] = i++;
        d.push_back(val);
    }

    for (auto x: d)
        cout << x << ' ';
    cout << '\n';

    return 0;
}
