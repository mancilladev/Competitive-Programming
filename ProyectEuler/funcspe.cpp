#include <cmath>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>

bool isPrime(int num) {
    // check if a number is prime
    if (num <= 3) {
        return num > 1;
    } else if (num % 2 == 0 or num % 3 == 0) {
        return false;
    }
    for (int i = 5; i <= sqrt(num); i += 2) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

bool isPalindrome(int num)
{
    // check if a number is a palindrome
    std::stringstream ss;
    ss << num;
    std::string str = ss.str();
    std::string strCopy = ss.str();
    std::reverse(strCopy.begin(), strCopy.end());
    return str == strCopy;
}

bool evenlyDivisible(int n, int till)
{
    // evenly divisible by all of the numbers from 1 to till
    for (int i = 2; i < till; ++i) {
        if (n%i != 0) {
            return false;
        }
    }
    return true;
}

int sumSquares(int n)
{
    // Sum of the squares of the first n integers
    // https://proofwiki.org/wiki/Sum_of_Sequence_of_Squares
    return (n * (n + 1) * (2 * n + 1 ) ) / 6;
}

long gaussSum(int n) { return (n * (n + 1)) / 2; }

bool arePythagoreanTriplete(int a, int b, int c) {
    return a*a + b*b == c*c;
}

std::vector<int> EratosthenesSieve(int limit)
{
    std::vector<int> boolean_list;
    std::vector<int> prime_list;
    int j;
    for (int i = 0; i <= limit * limit; ++i) {
         boolean_list.push_back(i);
    }
    // change composite nums to 0
    boolean_list[1] = 0;
    for (int i = 2; i <= limit * limit; ++i) {
        if (boolean_list[i]) {
            for (int j = i * i; j <= limit; j+=i) {
                boolean_list[j] = 0;
            }
        }
    }
    // append primes to prime_list
    for (auto i : boolean_list) {
        if (i) {
            prime_list.push_back(i);
        }
    }
    return prime_list;
}

int* SieveUntil(int limit)
{
    // difference with EratosthenesSieve
    // this func uses arrays
    int* numberlist = new int[limit+1];

    // Array of ones
    for (int i = 0; i < limit+1; ++i) numberlist[i] = 1;
    numberlist[0] = 0;
    numberlist[1] = 0;

    for (int i = 2; i < limit+1; ++i) {
        if (numberlist[i]) {
            for (int j = 2*i; j <= limit; j+=i) {
                numberlist[j] = 0;
            }
        }
    }
    
    return numberlist;
}

int Fibonacci(int n)
{
    int f[n+1];
    f[0] = 0;  f[1] = 1;
    for (int i = 2; i <= n; ++i) {
        f[i] = f[i-1] + f[i-2];
    }
    return f[n];
}

int Min(int a, int b)
{
    return (a<b) ? a : b;
}

int Max(int a, int b)
{
    return (a>b) ? a : b;
}

long BinomialCoefficient(int n, int k)
{
    long C[n+1][k+1];
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= Min(i,k); ++j) {
            if (j == 0 || j == i) C[i][j] = 1;
            else C[i][j] = C[i-1][j-1] + C[i-1][j];
        }
    }
    return C[n][k];
}

int SumOfDivisors(int n)
{
    // Proper divisors includes 1 and the number itself
    int sum = 1;
    for (int i = 2; i * i <= n; ++i) {
        if (n%i == 0) {
            // i.e. if 28/2 != 2, also count 14
            sum += i;
            if (n/i != i) sum += (n/i);
        }
    }
    return sum;
}
