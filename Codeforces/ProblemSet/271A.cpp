#include <iostream>
#include <set>
using namespace std;


int distinct_digits(int n) {
    set<int> s;
    while(n) {
        if(s.find(n%10)!=s.end()) return false;
        s.insert(n%10);
        n/=10;
    }
    return true;
}


int main() {
    int y;
    while(cin>>y) {
        while(!distinct_digits(++y));
        cout<<y<<endl;
    }
}
