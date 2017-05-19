#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


int main(){
    int Q;
    cin >> Q;
    for(int a0 = 0; a0 < Q; a0++){
        int n;
        cin >> n;
        string b;
        cin >> b;

        // if already happy, do nothing
        bool happy = true;
        for(int i = 0; i != n; i++)
            if(b[i] != b[max(i-1,0)] && b[i] != b[min(i+1,n-1)])
                happy = false;

        if(happy) {
            cout<<"YES"<<endl;
            continue;
        }


        // count frecuencies
        int frchar[30] = {};
        for(int i = 0; i != n; i++) {
            if(b[i] == '_') frchar[29]++;
            else frchar[b[i] - 'A']++;
        }

        int nmin = 1000;
        for(int i = 0; i != 29; i++)
            if(frchar[i] != 0) nmin = min(nmin, frchar[i]);

        // if there is a lonely bug or there are no _
        if(nmin != 1 && b.find('_') != string::npos)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}
