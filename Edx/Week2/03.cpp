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
#include <deque>
#include <set>
using namespace std;
  
int main() {
        int n; cin >> n;
        char k; int cur;

        deque<int> q;
        multiset<int> s;
        multiset<int>::iterator it;
        int t;

        while (cin >> k) {
                if (k == '+') {
                        cin >> cur;
                        q.push_back(cur);
                        s.insert(cur);
                }
                else if (k == '-') {
                        int t = q.front();
                        q.pop_front();

                        it = s.find(t);
                        s.erase(it);
                }
                else {
                        cout << *s.begin() << '\n';
                }
        }
        
        return 0;
}
