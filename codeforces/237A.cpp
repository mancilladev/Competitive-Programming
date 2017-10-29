#include <iostream>
#include <vector>
using namespace std;


int main() {
    int N; cin>>N;
    vector< pair<int,int> > v(N);
    for(int i = 0; i != N; i++)
        cin>>v[i].first>>v[i].second;

    int cnt = 1, sofar = 1;
    for(int i = 1; i != N; i++) {
        if(v[i].first == v[i-1].first && v[i].second == v[i-1].second) {
            sofar++;
            cnt = max(cnt, sofar);
        }
        else sofar = 1;
    }

    cout<<cnt<<endl;
}
