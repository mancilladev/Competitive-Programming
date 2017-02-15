#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> digits(int n) {
        vector<int> v;
        while(n) {
                v.push_back(n%10);
                n = n/10;
        }
        return v;
}


int main() {
        long long total = 0;
        for (int i = 11; i < 531441; i++) {
                vector<int> d = digits(i);

                int sumd = 0;
                for (auto& n : d) sumd += pow(n,5);

                if (sumd == i) {
                        total += sumd;
                }
        }
        cout<<total<<endl;

}
