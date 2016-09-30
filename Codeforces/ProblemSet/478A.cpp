#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define F(i,L,R) for(int i=L; i<R; i++)

int main() {
    vector<int> v(6);
    while(cin>>v[0]) {
        F(i,1,5) cin>>v[i];

        int sum = 0;
        F(i,0,5) {
            sum += v[i];
        }

        int mid = sum/5;
        if(sum!=0 && sum%5 == 0) cout<<mid<<endl;
        else cout<<-1<<endl;
    }
}
