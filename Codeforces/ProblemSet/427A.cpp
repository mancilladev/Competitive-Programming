#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N; cin>>N;
    vector<int> v(N);
    for(int i = 0; i != N; i++)
        cin>>v[i];

    int crimes = 0;
    int police = 0;
    for(int i = 0; i != N; i++) {
        if(v[i] == -1) {
            if(!police)
                crimes++;
            police = max(0, police-1);
        }
        else
            police += v[i];
    }
    cout<<crimes<<endl;
}
