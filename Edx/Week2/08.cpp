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
#include <string>
#include <deque>
#include <stack>
using namespace std;
  
int main() {
        int n; cin >> n;

        deque<int> d;
        int pos = -1;
        string s;
        int cur;

        for (int i = 0; i < n; i++) {
                cin >> s;
                if (s[0] == 'a') {
                        cin >> cur;
                        pos++;
                        d.insert(d.begin() + pos, cur);
                }
                else if (s[0] == 't') {
                        d.erase(d.begin() + pos);
                        pos--;
                }
                else if (d.size()) {
                        pos = (pos + (d.size())/2)%(d.size());
                }
        }

        cout << d.size() << endl;
        for (int i = pos+1; i < d.size(); i++)
                cout << d[i] << ' ';
        for (int i = 0; i <= pos; i++)
                cout << d[i] << ' ';
        cout << '\n';

        return 0;
}

