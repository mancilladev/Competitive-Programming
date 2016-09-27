#include <iostream>
using namespace std;

int main() {
    int x;
    while(cin>>x) {
        int steps = x/5;
        if(x%5) steps++;
        cout<<steps<<endl;
    }
}
