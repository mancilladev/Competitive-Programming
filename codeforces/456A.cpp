#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N;
    while(cin>>N) {
        vector< pair<int,int> > v(N);
        for(int i = 0; i != N; i++)
            cin>>v[i].first>>v[i].second;

        sort(v.begin(), v.end());

        bool happy = false;
        int lastmax = v[0].second;
        for(int i = 1; i != N; i++) {
            if(v[i].second < lastmax) {
                happy = true;
                break;
            }
            lastmax = v[i].second;
        }

        if(happy) cout<<"Happy Alex"<<endl;
        else cout<<"Poor Alex"<<endl;
    }
}
