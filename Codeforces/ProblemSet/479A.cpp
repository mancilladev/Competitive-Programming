#include <iostream>
using namespace std;

int main() {
    int a,b,c;
    while(cin>>a>>b>>c) {
        int num = a+b+c;
        num = max(num, (a+b)*c);
        num = max(num, a*(b+c));
        num = max(num, a*b*c);
        cout<<num<<endl;
    }
}
