#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N; cin>>N;

    int cnt[4] = {};
    vector<int> v(N);
    for(int i = 0; i != N; i++) {
        cin>>v[i];
        cnt[v[i]]++;
    }

    int numg = min(cnt[1], min(cnt[2], cnt[3]));
    cout<<numg<<endl;

    vector<int>::iterator it;
    for(int i = 0; i != numg; i++) {
        for(int j = 1; j != 4; j++) {
            it = find(v.begin(), v.end(), j);
            int pos = it-v.begin();
            cout<<pos+1;
            v[pos] = -1;
            if(j == 3) cout<<endl;
            else cout<<" ";
        }
    }
}
