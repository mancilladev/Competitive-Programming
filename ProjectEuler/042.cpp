#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main () {
        vector<bool> triangle(76245, 0);
        int cur = 0;
        for(int i = 1; i <= 390; i++)
                triangle[cur += i] = 1;

        ifstream is("file_042.txt");
        char c;
        int cnt = 0;

        while(is.get(c)) {
                if(c == '"') {
                        int sum = 0;
                        while(is.get(c)) {
                                if(c == '"') break;
                                sum += (c - 'A' + 1);
                        }
                        if(triangle[sum]) cnt++;
                }
        }

        cout<<cnt<<endl;
        is.close();
}
