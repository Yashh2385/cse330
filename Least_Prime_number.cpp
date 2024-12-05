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

// Function to find the smallest prime number less than or equal to n
int leastPrimeNumber(int n) 
{
    for (int i = 2; i <= n; i++) 
    {
        if (isPrime(i)) 
            return i;
    }
    return -1; 
}

int main() 
{
    int n;

    cout << "Enter a number: ";
    cin >> n;

    int result = leastPrimeNumber(n);
    if (result != -1)
        cout << "The least prime number less than or equal to " << n << " is: " << result << endl;
    else
        cout << "No prime numbers exist less than or equal to " << n << "." << endl;

    return 0;
}
