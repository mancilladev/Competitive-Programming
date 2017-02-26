#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main () {
        int n;
        string a, b;
        cin>>n;
        cin>>a>>b;
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        int j = n-1;
        for (int i = n-1; i >= 0; i--)
                if (b[j] >= a[i])
                        j--;
        cout<<j+1<<endl;
        j = 0;
        for (int i = 0; i < n; i++)
                if (b[i] > a[j])
                        j++;
        cout<<j<<endl;
}
