#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
using namespace std;


int main() {
    int N; cin>>N;
    vector<string> v(N);
    map< string, int > db;
    for(int i = 0; i != N; i++)
        cin>>v[i];

    for(int i = 0; i != N; i++) {
        if(db.find(v[i]) == db.end()) {
            cout<<"OK"<<endl;
            db[v[i]] = 0;
        }
        else {
            int big = db[v[i]];
            db[v[i]] = ++big;
            string s = v[i] + to_string(big);
            cout<<s<<endl;
        }
    }
}
