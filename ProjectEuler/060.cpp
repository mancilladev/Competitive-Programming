#include <bits/stdc++.h>
#define PB push_back
using namespace std;
const int MAX = 1000000, L = 25000;
vector<bool> isp(MAX+7, true);

int combine(int x, int y) {
    int times = 1;
    while (times <= y)
        times *= 10;
    return x * times + y;
}

bool solves(vector<int> v) {
    do {
        if (!isp[combine(v[0], v[1])] )
            return false;
    } while ( next_permutation(v.begin(), v.end()) );

    return true;
}

int main () {
    for (int i = 3; i * i <= MAX; i+=2) if (isp[i])
        for (int j = i*i; j < MAX; j += i) isp[j] = 0;

    vector<int> p;
    for (int i = 3; i < MAX; i+=2)
        if (isp[i])
            p.PB(i);

    for (int a = 0; a < p.size() && p[a] < L; ++a) {
        for (int b = a+1; b < p.size() && p[b] < L && combine(p[b], p[a]) < MAX; ++b) {
            for (int c = b+1; c < p.size() && p[c] < L && combine(p[c], p[b]) < MAX; ++c) {
                for (int d = c+1; d < p.size() && p[d] < L && combine(p[d], p[c]) < MAX; ++d) {
                    for (int e = d+1; e < p.size() && p[e] < L && combine(p[e], p[d]) < MAX; ++e) {
                        if (solves({p[a], p[b], p[c], p[d], p[e]}) ) {
                            cout << "Answer: " << (p[a] + p[b] + p[c] + p[d] + p[e]) << endl;
                            return 0;
                        }
                    }
                }
            }
        }
    }

    return 0;
}
