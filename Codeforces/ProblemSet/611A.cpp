#include <vector>
#include <string>
#include <sstream>
#include <iostream>
using namespace std;

int main() {
    vector<int> month_len {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    string action;
    while(getline(cin, action)) {
        if(action.find("week") != string::npos) {
            if(action[0] == '5' || action[0] == '6') cout<<53<<endl;
            else cout<<52<<endl;
        }
        else {
            int day;
            string tmp1, tmp2;
            stringstream ss(action);
            ss>>day>>tmp1>>tmp2;

            int sum = 0;
            for(int i = 0; i != month_len.size(); i++)
                if(month_len[i] >= day) sum++;
            cout<<sum<<endl;
        }
    }
}
