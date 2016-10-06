#include <iostream>
using namespace std;

int main() {
    int N,K;
    while(cin>>N>>K) {
        if(K > N || min(K,N) < 1) {
            cout<<-1<<endl;
            continue;
        }

        int res = N/2 + N%2;
        int left = N/2;

        while(left && res%K!=0) {
            res++;
            left--;
        }
        if(res%K!=0) res = -1;

        cout<<res<<endl;
    }
}
