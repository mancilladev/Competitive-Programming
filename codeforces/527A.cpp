#include <iostream>
using namespace std;


int main() {
    long long a, b;
    while(cin>>a>>b) {
        long long ships = 0;

        while(a > 0 && b > 0) {
            if(a >= b) {
                ships += a/b;
                a %= b;
            }
            else {
                ships += b/a;
                b %= a;
            }
        }

        cout<<ships<<endl;
    }
}
