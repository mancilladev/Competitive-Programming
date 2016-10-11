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

        long long sum = 0;
        for(int i = 0; i != N; i++)
            sum += v[i];

        int j = 0;
        while(j != N && sum%2 == 1) {
            if(v[j]%2 == 1) sum -= v[j];
            j++;
        }
        cout<<sum<<endl;
    }
}
