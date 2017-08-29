#include <set>
#include <iostream>
using namespace std;

int main() {
    int N, M;
    while(cin>>N>>M) {
        int times, tmp;
        set<int> s;
        for(int i = 0; i != N; i++) {
            cin>>times;
            for(int j = 0; j != times; j++) {
                cin>>tmp;
                s.insert(tmp);
            }
        }

        bool possible = true;
        for(int i = 0; i != M; i++) {
            if(s.find(i+1) == s.end()) {
                possible = false;
                break;
            }
        }

        if(possible) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}
