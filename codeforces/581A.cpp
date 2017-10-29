#include <iostream>
using namespace std;

int main() {
    int r,b;
    while(cin>>r>>b) {
        cout<<min(r,b)<<" "<<(max(r,b)-min(r,b))/2<<endl;
    }
}
