#include <iostream>
#include <vector>
using namespace std;

int main () {
        int cnt = 0;

        vector< vector<long long> > pTriangle(101, vector<long long>(101, 0));
        for (int i = 0; i < pTriangle.size(); i++)
                pTriangle[i][0] = 1;

        for (int y = 1; y < pTriangle.size(); y++)
                for (int x = 1; x < pTriangle.size(); x++) {
                        pTriangle[y][x] = (pTriangle[y-1][x-1] + pTriangle[y-1][x])%1000000000000;
                        if (pTriangle[y][x] > 1000000)
                                cnt++;
                }

        cout<<cnt<<endl;
}
