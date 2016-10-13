#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int N; cin>>N;
    vector<int> v(N);
    for(int i = 0; i != N; i++)
        cin>>v[i];
    if(*min_element(v.begin(), v.end()) == 1) cout<<-1<<endl;
    else cout<<1<<endl;
}
