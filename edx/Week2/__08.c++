#ifdef JUDGE
#include <fstream>
std::ifstream cin("input.txt");
std::ofstream cout("output.txt");
#else
#include <iostream>
#endif
#include <map>
using namespace std;

class Node {
        public:
                int val;
                Node* next;
                Node* prev;
                Node (int n) {val = n;}
} ;

class Cycle {
                int _size = 0;
                Node* head = NULL;
                Node* tail = NULL;
        public:
                void push (int n) {
                        Node* node = new Node(n);
                        if (_size == 0) {
                                head = node;
                                tail = node;
                                node->next = head;
                                node->prev = tail;
                        }
                        else {
                                node->next = head;
                                node->prev = tail;
                                tail->next = node;
                                head->prev = node;
                                tail = node;
                        }
                        _size++;
                }
                void pop () {
                        Node* newtail = tail->prev;
                        newtail->next = head;
                        head->prev = newtail;

                        tail->next = NULL;
                        tail->prev = NULL;
                        tail = newtail;

                        _size--;
                }
                void move (int n) {
                        if (!_size) return;

                        while (n--)
                                head = head->next;
                        tail = head->prev;
                }
                void print () {
                        if (!_size) {
                                cout << '\n';
                                return;
                        }
                        Node* cur = head;
                        while (cur != tail) {
                                cout << cur->val << ' ';
                                cur = cur->next;
                        }
                        cout << cur->val << '\n';
                }
                auto size () {
                        return _size;
                }
} clist;
  
int main() {
        int n, cur; cin >> n;
        string s;

        for (int i = 0; i < n; i++) {
                cin >> s;
                if (s[0] == 'a') {
                        cin >> cur;
                        clist.push(cur);
                }
                else if (s[0] == 't') {
                        clist.pop();
                }
                else if (clist.size()) {
                        clist.move(clist.size()/2);
                }
        }

        cout << clist.size() << '\n';
        clist.print();

        return 0;
}
