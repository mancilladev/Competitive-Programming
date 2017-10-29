#include <iostream>
#include <set>
using namespace std;


int main() { 
    set<double> s;
    for(double i = 3; i != 100000; i++)
        s.insert((i-2)*180/i);

    int t;
    cin>>t;
    while(t--) {
        int a;
        cin>>a;
        if(s.find(a) != s.end()) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}
