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

        sort(v.begin(), v.end());
        cout<<v.back() - v[0]<<" ";

        // all equal
        long long cnt = count(v.begin(), v.end(), v[0]);
        if(cnt == N) {
            cout<<cnt*(cnt-1)/2<<endl;
            continue;
        }

        long long mn = 0, mx = 0;
        for(int i = 0; i != N; i++) {
            if(v[i] == v[0]) mn++;
            else if(v[i] == v.back()) mx++;
        }
        cout<<mn*mx<<endl;
    }
}
