#include <iostream>
#include <vector>
using namespace std;


int main() {
    int N; cin>>N;
    int cnt[2] = {};
    int a, b;
    for(int i = 0; i != N; i++) {
        cin>>a>>b;
        if(a > b) cnt[0]++;
        else if(b > a) cnt[1]++;
    }
    if(cnt[0] > cnt[1]) cout<<"Mishka"<<endl;
    else if(cnt[1] > cnt[0]) cout<<"Chris"<<endl;
    else cout<<"Friendship is magic!^^"<<endl;
}
