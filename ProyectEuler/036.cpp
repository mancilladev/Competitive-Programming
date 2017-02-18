#include <iostream>
#include <string>
#include <bitset>
#include <cassert>
using namespace std;

bool isPalindrome(string s) {
        for (int i = 0; i < s.length(); i++)
                if (s[i] != s[s.length()-i-1])
                        return false;
        return true;
}

int main () {
        int sum = 0;

        string str = bitset<32>(585).to_string();
        str.erase(0, str.find_first_not_of('0'));
        assert(isPalindrome(to_string(585)) && isPalindrome(str));

        for (int i = 1; i < 1000000; i++) {
                string str = bitset<32>(i).to_string();
                str.erase(0, str.find_first_not_of('0'));
                if (isPalindrome(to_string(i)) && isPalindrome(str))
                        sum += i;
        }

        cout<<sum<<endl;
}
