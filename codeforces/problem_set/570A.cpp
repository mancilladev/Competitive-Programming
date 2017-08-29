#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
#define all(x) x.begin(), x.end()

int main() {
    int N, M;
    cin>>N>>M;
    int candidatefr[N+1];
    memset(candidatefr, 0, sizeof candidatefr);
    vector< vector<int> > v(M, vector<int>(N));
    for(int y = 0; y != M; y++)
        for(int x = 0; x != N; x++)
            cin>>v[y][x];

    for(int y = 0; y != M; y++)
        candidatefr[distance(v[y].begin(), max_element(all(v[y])))]++;

    cout<<distance(candidatefr-1, max_element(candidatefr, candidatefr+N+1))<<endl;
}
