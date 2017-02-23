#include <iostream>
#include <string>
using namespace std;

int main () {
        int mult = 1;
        long long d = 1;
        long long cnt = 0;

        for (int i = 0; d <= 1000000; i++) {
                for (auto c : to_string(i)) {
                        if (cnt == d) {
                                d *= 10;
                                mult *= c - '0';
                        }
                        cnt++;
                }
        }
        cout<<mult<<endl;
}
