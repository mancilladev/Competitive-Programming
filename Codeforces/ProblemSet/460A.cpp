#include <iostream>
using namespace std;

int main() {
    int n, m;
    while(cin>>n>>m) {
        int i = 0;
        while(--n) {
            if(i%m==0) n++;
            i++;
        }
        if(i%m==0) ++i;
        cout<<i<<endl;
    }
}
