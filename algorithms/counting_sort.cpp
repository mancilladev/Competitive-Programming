#include <iostream>
#include <vector>
using namespace std;
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;

#define MAX 10000

int main() {
    vector<int> v {2, 3, 8, 7, 1, 2, 2, 2, 7, 3, 9, 8, 2, 1, 4, 2, 4, 6, 9, 2};
    int cnt[MAX] = {};
    for(auto i: v) cnt[i]++;

    int sig = 0;
    for(int i = 0; i != MAX; i++)
        for(int j = cnt[i]; j != 0; j--) {
            v[sig] = i;
            sig++;
        }

    for(int i = 0; i != v.size()-1; i++) cout<<v[i]<<" ";
    cout<<v[v.size()-1]<<endl;
}
