#ifdef JUDGE
#include <fstream>
std::ifstream cin("input.txt");
std::ofstream cout("output.txt");
#else
#include <iostream>
#endif
#include <vector>
#include <deque>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef long double ld;
int N;

int main() {
    cin >> N;

    ld sum = 0;
    deque<ll> dq;
    unordered_map<ll, ll> hash;
    while (N--) {
        char c;
        cin >> c;
        if (c == '+') {
            ll cur; cin >> cur;
            hash[cur]++;
            sum += cur;
            dq.push_back(cur);
        }
        else if (c == '?') {
            ld mean = sum / dq.size();
            if ((ll)mean == mean)
                cout << hash[(ll)mean] << '\n';
            else
                cout << "0\n";
        }
        else if (c == '-') {
            sum -= dq.front();
            hash[dq.front()]--;
            dq.pop_front();
        }
    }

    return 0;
}
