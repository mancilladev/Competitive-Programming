#include <set>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N;
    while(cin>>N) {
        vector<int> v(N);
        for(int i = 0; i != N; i++)
            cin>>v[i];

        set<int> s;
        for(int i = 0; i != N; i++)
            s.insert(v[i]);

        int mxcnt = 1;
        int cur = 1;
        sort(v.begin(), v.end());
        for(int i = 1; i != N; i++) {
            if(v[i] == v[i-1])
                cur++;
            else
                cur = 1;
            mxcnt = max(mxcnt, cur);
        }

        cout<<mxcnt<<" "<<s.size()<<endl;
    }
}
