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

        vector<int> sec(N);
        copy(v.begin(), v.end(), sec.begin());
        sort(sec.begin(), sec.end());

        for(int i = 0; i != N; i++) {
            for(int j = N-1; j != -1; j--) {
                if(v[i] == sec[j]) {
                    cout<<N-j<<" ";
                    break;
                }
            }
        }
        cout<<endl;
    }
}
