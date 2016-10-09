#include <iostream>
#include <vector>
using namespace std;


int main() {
    int N; cin>>N;
    vector<long long> v(N);
    for(int i = 0; i != N; i++)
        cin>>v[i];

    long long unsigned nmin, nmax;
    if (N == 2) for(int i = 0; i != N; i++) {
        nmin = abs(v[0]-v[1]);
        cout<<nmin<<" "<<nmin<<endl;
    }
    else for(int i = 0; i != N; i++) {
        nmin = min(abs(v[i]-v[(i-1)%N]), abs(v[i]-v[(i+1)%N]));
        nmax = max(abs(v[i]-v[0]), abs(v[i]-v.back()));
        cout<<nmin<<" "<<nmax<<endl;
    }
}
