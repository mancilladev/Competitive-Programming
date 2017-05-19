#ifdef JUDGE
#include <fstream>
std::ifstream cin("input.txt");
std::ofstream cout("output.txt");
#else
#include <iostream>
using std::cin;
using std::cout;
#endif
#include <queue>
using namespace std;
  
int main() {
        int n; cin >> n;
        char k; int cur;
        queue<int> q;

        while (n--) {
                cin >> k;
                if (k == '+') {
                        cin >> cur;
                        q.push(cur);
                }
                else {
                        cout << q.front() << '\n';
                        q.pop();
                }
        }
        
        return 0;
}
