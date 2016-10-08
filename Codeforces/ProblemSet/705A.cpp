#include <iostream>
#include <vector>
using namespace std;


int main() {
    int N; cin>>N;
    int i = 1;
    while(i <= N) {
        if(i%2 == 0)
            cout<<"I love ";
        else
            cout<<"I hate ";
        if(N != i) cout<<"that ";
        i++;
    }
    cout<<"it"<<endl;
}
