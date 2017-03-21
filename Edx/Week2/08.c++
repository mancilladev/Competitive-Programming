#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
using namespace std;

struct Table {
        deque<int>* main;
        deque<int>* sec;
} ;
  
int main() {
#ifdef JUDGE
freopen("input.txt", "rt", stdin);
freopen("output.txt", "wt", stdout);
#endif
ios::sync_with_stdio(false);

        int n; cin >> n;

        Table t;
        t.main = new deque<int>();
        t.sec = new deque<int>();
        string s;
        int cur;

        for (int i = 0; i < n; i++) {
                cin >> s;
                if (s[0] == 'a') {
                        cin >> cur;
                        t.main->push_back(cur);
                        if (t.sec->size() + 1 < t.main->size()) {
                                t.sec->push_back(t.main->front());
                                t.main->pop_front();
                        }
                }
                else if (s[0] == 't') {
                        t.main->pop_back();
                        if (t.sec->size() > t.main->size()) {
                                t.main->push_front(t.sec->back());
                                t.sec->pop_back();
                        }
                }
                else if ((t.main->size() + t.sec->size()) > 1) {
                        deque<int>* tmp = t.main;
                        t.main = t.sec;
                        t.sec = tmp;
                }
                /*
                for (auto x: *t.main)
                        cout << x << ' ';
                cout << "| ";
                for (auto x: *t.sec)
                        cout << x << ' ';
                cout << '\n';
                */
        }

        cout << (t.main->size() + t.sec->size()) << endl;
        for (auto x: *t.sec)
                cout << x << ' ';
        for (auto x: *t.main)
                cout << x << ' ';
        cout << '\n';

        return 0;
}

