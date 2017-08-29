#include <vector>
#include <iostream>
using namespace std;

int main() {
    int n;
    while(cin>>n) {
        vector< vector<char> > v(n, vector<char>(n, '*'));
        int middle = n/2+1;

        // top
        for(int i = 0; i != middle; i++)
            for(int j = middle-i-1; j != middle+i; j++)
                v[i][j] = 'D';

        // bottom
        for(int i = middle; i != n; i++)
            v[i] = v[n-i-1];

        for(int i = 0; i != n; i++) {
            for(int j = 0; j != n; j++)
                cout<<v[i][j];
            cout<<endl;
        }
    }
}
