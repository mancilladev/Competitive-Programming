#include <iostream>
#include <vector>
using namespace std;


int main() {
    int N, M; cin>>N>>M;
    vector< vector<char> > v(N, vector<char>(M));
    for(int y = 0; y != N; y++)
        for(int x = 0; x != M; x++)
            cin>>v[y][x];

    for(int y = 0; y != N; y++)
        for(int x = 0; x != M; x++) {
            if(v[y][x] == 'C' || v[y][x] == 'M' || v[y][x] == 'Y') {
                cout<<"#Color"<<endl;
                return 0;
            }
        }
    cout<<"#Black&White"<<endl;
}
