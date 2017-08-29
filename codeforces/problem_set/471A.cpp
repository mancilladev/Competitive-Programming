#include <set>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


vector<int> cnt(10, 0);


bool HasLegs() {
    for(int i = 0; i != 10; i++) {
        if(cnt[i] >= 4) {
            cnt[i] -= 4;
            return true;
        }
    }
    return false;
}


bool IsBear() {
    int a=-1,b=-1;
    for(int i = 0; i != 10; i++) {
        if(cnt[i]) {
            if(a==-1) a = i;
            else b = i;
            cnt[i--]--;
        }
    }
    return a != b;
}

int main() {
    vector<int> v(6);
    while(cin>>v[0]) {
        for(int i = 1; i != 6; i++)
            cin>>v[i];

        fill(cnt.begin(), cnt.end(), 0);
        for(int i = 0; i != 6; i++)
            cnt[v[i]]++;

        if(!HasLegs()) cout<<"Alien"<<endl;
        else if(IsBear()) cout<<"Bear"<<endl;
        else cout<<"Elephant"<<endl;
    }
}
