#include <iostream>
#include <set>
#include <vector>
using namespace std;
#define F(i,L,R) for(int i=L; i<R; i++)

int main() {
    int n;
    while(cin>>n) {
        int p,q, temp;
        set<int> s;

        // first guy
        cin>>p;
        F(i,0,p) {
            cin>>temp;
            s.insert(temp);
        }

        // second guy
        cin>>q;
        F(i,0,q) {
            cin>>temp;
            s.insert(temp);
        }

        bool found = true;
        F(i,1,n+1) {
            if(s.find(i) == s.end()) {
                found = false;
                break;
            }
        }

        if(found) cout<<"I become the guy."<<endl;
        else cout<<"Oh, my keyboard!"<<endl;
    }
}
