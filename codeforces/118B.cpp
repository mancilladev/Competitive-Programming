#include <vector>
#include <string>
#include <iostream>
using namespace std;

int main() {
    int n;
    while(cin>>n) {
        vector< vector<int> > v(n*2+1, vector<int>(n*2+1, -1));

        // top and middle
        for(int i = 0; i != n+1; i++) {
            int num = 0;
            for(int j = n-i; j != n; j++)
                v[i][j] = num++;
            for(int j = n; j != n+i+1; j++)
                v[i][j] = num--;
        }
        // bottom
        for(int i = 0; i != n; i++)
            v[2*n-i] = v[i];

        // print
        for(int i = 0; i != v.size(); i++) {
            for(int j = 0; j != v.size()-1; j++) {
                if(v[i][j] == -1) cout<<" ";
                else cout<<v[i][j];
                if(j >=n && v[i][j+1] == -1) break;
                cout<<" ";
            }
            if(v[i].back() != -1) cout<<v[i].back();
            cout<<endl;
        }
    }
}
