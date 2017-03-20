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
#include <stack>
using namespace std;

int main() {
        int n; cin >> n;
        
        vector<int> total(n+1, 0);
        vector<int> top(n+1, 0);
        vector<int> past(n+1, 0);

        int pos;
        short val;
        for (int i = 1; i <= n; i++) {
                cin >> pos >> val;
                if (val) {
                        top[i] = val;
                        total[i] = total[pos] + val;
                        past[i] = pos;
                }
                else {
                        top[i] = top[past[pos]];
                        total[i] = total[past[pos]];
                        past[i] = past[past[pos]];
                }
        }

        long long sum = 0;
        for (auto x: total)
                sum += x;
        cout << sum << endl;

        return 0;
}

