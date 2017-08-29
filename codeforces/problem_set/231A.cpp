#include <iostream>
using namespace std;
int main() {
    int tests, temp, total, current;
    while(cin>>tests) {
        total = 0;
        for(int i=0; i!=tests; i++) {
            current = 0;
            for(int j=0; j!=3; j++) {cin>>temp; current+=temp;}
            if(current>1) total++;
        }
        cout<<total<<endl;
    }
}
