#include <iostream>
#include <string>
#include <locale>
using namespace std;
#define ll long long

int main() {
    string a;
    while(getline(cin, a)) {
        int words=0;
        for(int i=0; i < a.size(); i++) 
            if((isalpha(a[i])) && (!isalpha(a[i+1]))) words++;
        cout << words << endl;
    }
    return 0;
}
