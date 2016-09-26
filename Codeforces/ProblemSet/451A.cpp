#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int n,m;
    vector<string> v {"Malvika","Akshat"};
    while(cin>>n>>m) {
        cout<<v[min(n,m)%2]<<endl;
    }
}
