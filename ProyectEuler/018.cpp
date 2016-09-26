#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <fstream>
#include "funcspe.cpp"

#define MAX 15

int main(void)
{
    int triangle[MAX][MAX], counter = 0;
    long maximum = 0;
    std::vector<std::string> result;

    std::fstream file("file_018.txt");
    std::string str;
    
    std::getline(file, str);
    std::istringstream iss(str);

    for(std::string str; iss >> str; )
        result.push_back(str);

    for (int i = 0; i < MAX; ++i) {
        for (int j = 0; j <= i; ++j) {
            triangle[i][j] = std::stoi(result[counter++]);
            std::cout << triangle[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    for (int i = 1; i < MAX; ++i) {
        for (int j = 0; j <= i; ++j) {
            if (j == 0) triangle[i][j] += triangle[i-1][j];
            else if (j == i) triangle[i][j] += triangle[i-1][j-1];
            else triangle[i][j] += Max(triangle[i-1][j],triangle[i-1][j-1]);
            std::cout << triangle[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    for (int j = 0; j < MAX; ++j) {
        if (triangle[MAX-1][j] > maximum) maximum = triangle[MAX-1][j];
    }

    std::cout << maximum << std::endl;
    return 0;
}
