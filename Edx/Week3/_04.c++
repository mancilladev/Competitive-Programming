#ifdef JUDGE
#include <fstream>
std::ifstream cin("input.txt");
std::ofstream cout("output.txt");
#else
#include <iostream>
#endif
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

int main() {
    int n, k1, k2;
    int A, B, C, a1, a2;
    priority_queue<int> pq;

    cin >> n >> k1 >> k2;
    cin >> A >> B >> C >> a1 >> a2;
    pq.push(a1);
    pq.push(a2);
    if (pq.size() > k2)
        pq.pop();

    for (int i = 2; i < n; i++) {
        int tmp = A * a1 + B * a2 + C;
        pq.push(tmp);
        if (pq.size() > k2)
            pq.pop();
        a1 = a2;
        a2 = tmp;
    }

    stack<int> sk;
    for (int i = 0; i <= k2-k1; i++)
        sk.push(pq.top()), pq.pop();

    while (!sk.empty())
        cout << sk.top() << ' ', sk.pop();
    cout << '\n';

    return 0;
}
