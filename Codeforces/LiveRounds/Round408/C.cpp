#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#define HACKED -10000000000
typedef long long ll;
using namespace std;

struct Node {
    int pos;
    ll val;
} ;

bool anyH(auto& v, auto& hash, int j) {
    for (int x: hash[j])
        if (v[x].val == HACKED)
            return true;
    return false;
}

int main() {
    int N; cin >> N;
    vector<Node> v(N);
    map<int, vector<int> > hash;
    map<int, int> sum;

    for (int i = 0; i < N; ++i) {
        int tmp; cin >> tmp;
        v[i].val = tmp;
        v[i].pos = i;
        sum[i] = 0;
    }

    for (int i = 0; i < N-1; ++i) {
        int a, b; cin >> a >> b;
        if (hash.count(a))
            hash[a].push_back(b);
        else
            hash[a] = {b};

        if (hash.count(b))
            hash[b].push_back(a);
        else
            hash[b] = {a};
    }

    ll biggest=0;
    for (int i = 0; i < N; ++i) {
        int cur = 0;
        for (int j = 1; j < N; ++j) {
            if (v[j].val + sum[j] > v[cur].val + sum[cur] && (i==0 || anyH(v, hash, j)))
                cur = j;
        }

        Node &node = v[cur];
        biggest = max(biggest, node.val + sum[cur]);
        node.val = HACKED;
        for (int x: hash[cur]) {
            ++sum[x];
            for (int y: hash[x])
                ++sum[y];
        }
    }

    cout << biggest << '\n';

    return 0;
}
