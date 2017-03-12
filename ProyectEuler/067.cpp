#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

#define MAX 100

using namespace std;

int main(void)
{
    int triangle[MAX][MAX], counter = 0;
    int ans = 0;
    vector<string> result;

    ifstream file;
    file.open("file_067.txt");

    string str;

    while (file >> str)
        result.push_back(str);

    for (int i = 0; i < MAX; i++)
        for (int j = 0; j <= i; j++)
            triangle[i][j] = stoi(result[counter++]);

    for (int i = 1; i < MAX; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0)
                    triangle[i][j] += triangle[i-1][j];
            else if (j == i)
                    triangle[i][j] += triangle[i-1][j-1];
            else
                    triangle[i][j] += max(triangle[i-1][j], triangle[i-1][j-1]);
        }
    }

    for (int j = 0; j < MAX; j++)
        ans = max(ans, triangle[MAX-1][j]);

    cout << ans << endl;
    return 0;
}
