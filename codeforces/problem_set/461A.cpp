#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin>>N;

    vector<long long> v(N);
    for(int i = 0; i != N; i++)
        cin>>v[i];

    sort(v.begin(), v.end());

    long long score = v.size()*v.back();
    for(int i = 0; i != N-1; i++) {
        score += (2+i) * v[i];
    }

    cout<<score<<endl;
}
