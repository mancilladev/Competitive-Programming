#include <iostream>
#include <vector>
using namespace std;


int main() {
    int N, H;
    cin>>N>>H;
    vector<int> v(N);
    for(int i = 0; i != N; i++)
        cin>>v[i];

    int w = 0;

    for(int i = 0; i != N; i++) {
        if(v[i] > H) w += 2;
        else w++;
    }

    cout<<w<<endl;
}
