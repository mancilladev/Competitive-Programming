#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, money;
    while(cin>>n>>money) {
        vector< vector<int> > v(n);
        vector<int> index;

        int tmp, times;
        for(int i = 0; i != n; i++) {
            cin>>times;
            for(int j = 0; j != times; j++) {
                cin>>tmp;
                v[i].push_back(tmp);
            }
        }

        for(int i = 0; i != n; i++) {
            if(*min_element(v[i].begin(), v[i].end()) < money)
                index.push_back(i+1);
        }

        cout<<index.size()<<endl;
        if(index.size()) {
            for(int i = 0; i != index.size()-1; i++) cout<<index[i]<<" ";
            cout<<index.back()<<endl;
        }
    }
}
