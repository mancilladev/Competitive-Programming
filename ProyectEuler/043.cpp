#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int digits[] = {0,1,2,3,4,5,6,7,8,9};
int seq[] = {2,3,5,7,11,13,17};
long long sum = 0;

bool solves() {
        for (int i = 0; i < 7; i++) {
                int num = digits[1+i] * 100;
                num += digits[2+i] * 10;
                num += digits[3+i];
                if (num%seq[i] != 0)
                        return false;
        }
        return true;
}

long long getnum() {
        string num = "";
        for (int d: digits)
                num += to_string(d);
        return stol(num);
}

int main () {
        do {
                if(solves())
                        sum += getnum();
        } while (next_permutation(digits, digits+10));
        cout<<sum<<endl;
}
