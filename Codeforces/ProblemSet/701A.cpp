#include <vector>
#include <iostream>
using namespace std;

int main() {
    int N;
    while(cin>>N) {
        vector<int> v(N);
        int sum = 0;
        for(int i = 0; i != N; i++) {
            cin>>v[i];
            sum += v[i];
        }

        sum /= (N/2);

        for(int i = 0; i != N; i++) {
            for(int j = i+1; j != N; j++) {
                if(v[i] + v[j] == sum) {
                    cout<<i+1<<" "<<j+1<<endl;
                    v[i] = -1;
                    v[j] = -1;
                }
            }
        }
    }
}
