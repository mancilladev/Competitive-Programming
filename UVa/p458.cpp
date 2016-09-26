#include <iostream>
#include <string>
#include <locale>
#include <vector>
using namespace std;


bool readable_english(string d) {
    vector<string> pop_words = {"the", "in", "for", "of", "is", "so", "and", "...", "with", "to", "in", "that", "it"};
    for(auto s: pop_words)
        if(d.find(s) <= d.size())
            return true;
    return false;
}


int main() {
    string line;
    while(getline(cin, line)) {
        string decoded;
        cout << line << endl;

        for(int step=-127; step<=127; step++) {
            decoded.clear();
            for(int j=0; j<line.size(); j++) {
                char c = (char)(line[j]+step);
                decoded.push_back(c);
            }
            if(decoded.find(' ') <= line.size() && readable_english(decoded)) {
                cout << decoded << endl;
                break;
            }
        }
        cout << endl;
    }
    return 0;
}
