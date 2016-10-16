#include <vector>
#include <iostream>
using namespace std;

int main() {
    int N;
    while(cin>>N) {
        vector<int> v(N);
        for(int i = 0; i != N; i++)
            cin>>v[i];

        int tf = 0, ff = 0;
        bool no = false;
        for(int i = 0; i != N; i++) {
            if(v[i] == 25) tf++;
            else if(v[i] == 50 && tf) {
                tf--;
                ff++;
            }
            else if(v[i] == 100 && ff && tf) {
                tf--;
                ff--;
            }
            else if(v[i] == 100 && tf > 2) {
                tf -= 3;
            }
            else {
                cout<<"NO"<<endl;
                no = true;
                break;
            }
        }
        if(no) continue;
        cout<<"YES"<<endl;
    }
}
