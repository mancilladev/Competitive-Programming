#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N; cin>>N;
    vector<int> v(N);
    int S = 0;

    for(int i = 0; i != N; i++) {
        cin>>v[i];
        if(v[i]) {
            v[i] = -1;
            S++;
        }
        else v[i] = 1;
    }

    int biggest = v[0];
    for(int i = 1; i != N; i++) {
        v[i] = max(v[i], v[i]+v[i-1]);
        biggest = max(biggest, v[i]);
    }

    cout<<S+biggest<<endl;
}
