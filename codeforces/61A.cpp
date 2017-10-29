#include <iostream>
#include <string>
using namespace std;

int main() {
    string a,b;
    while(cin>>a>>b) {
        string s;
        for(int i=0; i!=a.length(); i++) if(a[i]==b[i]) s+='0'; else s+='1';
        cout<<s<<endl;
    }
}
