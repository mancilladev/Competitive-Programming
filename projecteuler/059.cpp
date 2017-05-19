#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
std::ifstream file("file_059.txt");
using namespace std;

vector<int> word = {116, 104, 101, 32};
vector<int> key = {1, 1, 1};
vector<int> nums;

void xorVector() {
        for (int i = 0; i < nums.size(); i+=3)
                for (int j = 0; j < 3 && i + j < nums.size(); j++)
                        nums[i+j] ^= key[j];
}

void solve() {
        for (int a = 'a'; a <= 'z'; a++) {
                key[0] = a;
                for (int b = 'a'; b <= 'z'; b++) {
                        key[1] = b;
                        for (int c = 'a'; c <= 'z'; c++) {
                                key[2] = c;
                                xorVector();
                                if (search(nums.begin(), nums.end(), word.begin(), word.end()) != nums.end()) {
                                        cout<<(char)a<<(char)b<<(char)c<<endl;
                                        return;
                                }
                                else
                                        xorVector();
                        }
                }
        }
}

int main () {
        int tmp;
        while (file>>tmp)
                nums.push_back(tmp);

        solve();

        unsigned long long sum = 0;
        for (int x: nums) {
                sum += x;
                cout<<(char)x;
        }

        cout<<endl;
        cout<<sum<<endl;
}
