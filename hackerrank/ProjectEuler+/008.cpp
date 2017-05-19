#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int T; cin>>T;
    while(T--) {
        int N, K;
        cin>>N>>K;

        vector<int> v(N);
        string s; cin>>s;
        for(int i=0; i!=N; ++i)
            v[i] = s[i] - '0';

        int gp = 0;

        for(int i=0; i+K!=N; i++) {
            int p = 1;
            for(int j=0; j!=K; j++)
                p *= v[i+j];
            gp = max(gp, p);
        }

        cout<<gp<<endl;
    }
    return 0;
}
