#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main() {
    int n;
    while(cin>>n) {
        string fi,sec;
        fi = to_string(n);
        sec = to_string(n);

        sec.pop_back();
        sec.pop_back();
        sec += fi.back();
        fi.pop_back();

        int a,b;
        istringstream(sec)>>a;
        istringstream(fi)>>b;

        if(fi.back() == '-') a = -11111;

        cout<<max(n, max(a,b))<<endl;
    }
}
