#ifdef JUDGE
#include <fstream>
std::ifstream cin("input.txt");
std::ofstream cout("output.txt");
#else
#include <iostream>
using std::cin;
using std::cout;
#endif
#include <stack>
using namespace std;
  
int main() {
    int n; cin >> n;
    char k;
    int cur;
    stack<int> s;
    for (int i = 0; i < n; i++) {
            cin >> k;
            if (k == '+') {
                    cin >> cur;
                    s.push(cur);
            }
            else {
                    cout << s.top() << '\n';
                    s.pop();
            }
    }
    return 0;
}
