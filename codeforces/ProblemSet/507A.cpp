#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N, K;
    while(cin>>N>>K) {
        vector< pair<int,int> > v(N);
        for(int i = 0; i != N; i++) {
            cin>>v[i].first;
            v[i].second = i+1;
        }

        sort(v.begin(), v.end());
        vector<int> index;
        for(int i = 0; i != N; i++) {
            K -= v[i].first;
            if(K < 0) break;
            index.push_back(v[i].second);
        }

        cout<<index.size()<<endl;
        if(index.size()) {
            for(int i = 0; i != index.size()-1; i++) cout<<index[i]<<" "; cout<<index.back()<<endl;
        }
    }
}
