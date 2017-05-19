#include <vector>
#include <iostream>
using namespace std;


int main() {
    int m, s;
    while(cin>>m>>s) {
        if( 9*m < s || (s == 0 && m > 1)) {
            cout<<-1<<" "<<-1<<endl;
            continue;
        }

        vector<int> small(m, 0);
        if(s > 0) small[0] = 1;
        vector<int> big(m, 9);
        int change;

        // min number
        int minsum = 1;
        change = m-1;
        while(minsum < s) {
            if(small[change] < 9) {
                small[change]++;
                minsum++;
            }
            else change--;
        }

        for(int i = 0; i != m-1; i++)
            cout<<small[i];
        cout<<small.back()<<" ";


        // max number
        int maxsum = m*9;
        change = m-1;
        while(maxsum > s) {
            if(big[change] > 0) {
                big[change]--;
                maxsum--;
            }
            else change--;
        }

        for(int i = 0; i != m-1; i++)
            cout<<big[i];
        cout<<big.back()<<endl;
    }
}
