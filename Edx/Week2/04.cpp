#ifdef JUDGE
#include <fstream>
std::ifstream cin("input.txt");
std::ofstream cout("output.txt");
#else
#include <iostream>
using std::cin;
using std::cout;
#endif
#include <string>
#include <stack>
using namespace std;


bool solves(string str) {
        stack<char> s;
        for (char c: str) {
                if (c == '(' || c == '[')
                        s.push(c);
                else if (s.size() == 0 || (c == ')' && s.top() != '(') || (c == ']' && s.top() != '['))
                        return false;
                else
                        s.pop();
        }
        return s.size() == 0;
}
  
int main() {
        int n; cin >> n;
        char c;
        string str;

        while (n--) {
                cin >> str;
                cout << (solves(str) ? "YES" : "NO") << endl;
        }

        return 0;
}
