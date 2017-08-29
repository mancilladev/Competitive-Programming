#include <iostream>
using namespace std;

int main() {
    int N, X;
    cin>>N>>X;

    int cnt = 0;

    for(int i = 1; i <= N; i++) {
        if(X%i == 0 && X/i <= N) cnt++;
    }

    cout<<cnt<<endl;
}
