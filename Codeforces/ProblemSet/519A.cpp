#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;


int main() {
    string wvalues = "PNBRQ";
    string bvalues = "pnbrq";
    map<char,int> m = {
        {'p', 1},
        {'n', 3},
        {'b', 3},
        {'r', 5},
        {'q', 9}
    };
    vector<string> v(8);
    for(int i = 0; i != 8; i++)
        cin>>v[i];

    int b = 0, w = 0;
    for(int i = 0; i != 8; i++) {
        for(int j = 0; j != 8; j++) {
            if(wvalues.find(v[i][j]) != string::npos)
                w += m.find(tolower(v[i][j]))->second;
            else if(bvalues.find(v[i][j]) != string::npos) 
                b += m.find(tolower(v[i][j]))->second;
        }
    }
    
    if(b>w) cout<<"Black"<<endl;
    else if(w>b) cout<<"White"<<endl;
    else cout<<"Draw"<<endl;
}
