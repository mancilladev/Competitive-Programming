#include <iostream>
#include <string>
using namespace std;

int main() {
    string S; cin>>S; cin>>S;
    int o = 0, z = 0;
    for(int i = 0; i != S.length(); i++) {
        if(S[i] == '1') o++;
        else z++;
    }
    cout<<abs(o-z)<<endl;
}
