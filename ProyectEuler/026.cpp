#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

int CycleLength(int n)
{
    std::vector<int> dividend_history;
    int dividend = 10;

    while (dividend && std::find(dividend_history.begin(), dividend_history.end(), dividend) == dividend_history.end()) {
        dividend_history.push_back(dividend);
        dividend = (dividend%n) * 10;
    }

    if (dividend) {
        int pos = std::find(dividend_history.begin(), dividend_history.end(), dividend) - dividend_history.begin();
        return dividend_history.size() - pos;
    } else {
        // 10%2*10 = 0 and that has got no cycle
        return 0;
    }
}

int main(void)
{
    int temp, d;
    int last_cycle = 0;

    for (int i = 2; i < 1000; ++i) {
        temp = CycleLength(i);
        if (temp > last_cycle) {
            last_cycle = temp;
            d = i;
        }
    }

    std::cout << d << std::endl;
    return 0;
}
