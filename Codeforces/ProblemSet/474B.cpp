#include <vector>
#include <iostream>
using namespace std;


int main() {
    int N;
    while(cin>>N) {
        int index[1000004] = {};
        vector<long long> w(N);
        int last = 0;
        for(int i = 0; i != N; i++) {
            cin>>w[i];
            for(int j = 0; j != w[i]; j++)
                index[++last] = i+1;
        }

        int M; cin>>M;
        int temp;
        for(int i = 0; i != M; i++) {
            cin>>temp;
            cout<<index[temp]<<endl;
        }

    }
}
