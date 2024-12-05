#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int num) 
{
    if (num <= 1) return false;
    if (num <= 3) return true;
    if (num % 2 == 0 || num % 3 == 0) return false;

    for (int i = 5; i * i <= num; i += 6) 
    {
        if (num % i == 0 || num % (i + 2) == 0)
            return false;
    }
    return true;
}

int largestPrime(int n) 
{
    for (int i = n; i >= 2; i--) 
    {
        if (isPrime(i)) 
        {
            return i; 
        }
    }
    return -1; 
}

int main() 
{
    int n;
    cout << "Enter a number: ";
    cin >> n;

    int result = largestPrime(n);

    if (result == -1) 
    {
        cout << "No primes exist below " << n << "." << endl;
    } 
    else 
    {
        cout << "The largest prime number less than or equal to " << n << " is: " << result << endl;
    }

    return 0;
}
