#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int N; cin>>N;
    vector<string> v(N);
    for(int i = 0; i != N; i++)
        cin>>v[i];
    bool both = false;

    for(int i = 0; i != N; i++) {
        if(v[i][0] == 'O' && v[i][1] == 'O') {
            v[i][0] = '+';
            v[i][1] = '+';
            both = true;
            break;
        }
        if(v[i][3] == 'O' && v[i][4] == 'O') {
            v[i][3] = '+';
            v[i][4] = '+';
            both = true;
            break;
        }
    }

    if(both) {
        cout<<"YES"<<endl;
        for(int i = 0; i != N; i++)
            cout<<v[i]<<endl;
    }
    else cout<<"NO"<<endl;
}
