#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N; cin>>N;
    vector<int> v(12);
    for(int i = 0; i != 12; i++)
        cin>>v[i];
    sort(v.begin(), v.end(), greater<int>());

    int sum = 0;
    int i = 0;
    for(; i != 12; i++) {
        if(sum >= N) break;
        sum += v[i];
    }

    if(sum >= N) cout<<i<<endl;
    else cout<<-1<<endl;
}
