#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Day {
    int h, v;
};

int main() {
    int N;
    while(cin>>N) {
        vector<Day> days(N*N);
        for(int i = 0; i != N*N; i++) {
            cin>>days[i].h>>days[i].v;
        }

        vector<int> worked, horizontal, vertical;
        for(int i = 0; i != N*N; i++) {
            if(find(horizontal.begin(), horizontal.end(), days[i].h) == horizontal.end()
                    && find(vertical.begin(), vertical.end(), days[i].v) == vertical.end()) {
                worked.push_back(i+1);
                horizontal.push_back(days[i].h);
                vertical.push_back(days[i].v);
            }
        }
        for(int i = 0; i != worked.size()-1; i++) cout<<worked[i]<<" "; cout<<worked.back()<<endl;
    }
}
