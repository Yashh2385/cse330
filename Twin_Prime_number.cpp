#include <iostream>
#include <cmath>
using namespace std;

// Function to check if a number is prime
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

// Function to find and display twin primes up to n
void findTwinPrimes(int n) 
{
    cout << "Twin primes up to " << n << " are:" << endl;

    int prevPrime = 2; // Start with the first prime number
    for (int i = 3; i <= n; i++) 
    {
        if (isPrime(i)) 
        {
            if (i - prevPrime == 2) // Check for twin prime condition
            { 
                cout << "(" << prevPrime << ", " << i << ")" << endl;
            }
            prevPrime = i;
        }
    }
}

int main() 
{
    int n;
    cout << "Enter the upper limit: ";
    cin >> n;

    // Find and display twin primes
    if (n < 2) 
    {
        cout << "No twin primes exist for numbers less than 2." << endl;
    } 
    else 
    {
        findTwinPrimes(n);
    }

    return 0;
}
