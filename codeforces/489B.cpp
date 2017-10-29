#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    while(cin>>n) {
        vector<int> boy(n);
        for(int i = 0; i != n; i++)
            cin>>boy[i];

        cin>>m;
        vector<int> girl(m);
        for(int i = 0; i != m; i++)
            cin>>girl[i];

        sort(boy.begin(), boy.end());
        sort(girl.begin(), girl.end());

        int b = 0, g = 0, cnt = 0;
        while(true) {
            if(b == n || g == m) break;
            if(abs(boy[b] - girl[g]) < 2) {
                b++; g++; cnt++;
            }
            else if(girl[g] - boy[b] > 1) b++;
            else g++;
        }

        cout<<cnt<<endl;
    }
}
