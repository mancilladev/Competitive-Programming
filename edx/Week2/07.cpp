#ifdef JUDGE
#include <fstream>
std::ifstream cin("input.txt");
std::ofstream cout("output.txt");
#else
#include <iostream>
using std::cin;
using std::cout;
#endif
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
  
int main() {
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    multiset<int> stacks;
    for (int i = 0; i < n; i++) {
        if (v[i]) {
            stacks.insert(1);
        }
        else {
            if (stacks.size()) {
                stacks.insert(*stacks.begin() + 1);
                stacks.erase(stacks.begin());
            }
            else stacks.insert(1);
        }
    }
    cout << *stacks.rbegin() << endl;

    return 0;
}
