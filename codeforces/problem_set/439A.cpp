#include <iostream>
#include <vector>
using namespace std;


int main() {
    int N, D;
    cin>>N>>D;
    vector<int> v(N);
    for(int i = 0; i != N; i++)
        cin>>v[i];

    int s = 10*(N-1);
    for(int i = 0; i != N; i++)
        s += v[i];
    int cnt = (N-1)*2 + (D - s)/5;

    if(s > D) cout<<-1<<endl;
    else cout<<cnt<<endl;
}
