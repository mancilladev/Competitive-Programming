#include <iostream>
using namespace std;

int main() {
    int n, a, b;
    cin>>n>>a>>b;
    --a;
    for(int i = 0; i != abs(b); i++) {
        if(b < 0) {
            --a;
            if(a < 0) a = n-1;
        }
        else {
            a = (++a)%n;
        }
    }
    cout<<a+1<<endl;
}
