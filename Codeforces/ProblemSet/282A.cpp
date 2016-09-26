#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    while(cin>>n) {
        int x = 0;
        for(int i=0; i!=n; i++) {
            string op;
            cin>>op;
            for(int j=0; j!=op.length(); j++) {
                if(op[j]=='+') {
                    x++;
                    break;
                } else if(op[j]=='-') {
                    x--;
                    break;
                }
            }
        }
        cout<<x<<endl;
    }
}
