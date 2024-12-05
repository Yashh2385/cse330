#include <iostream>
#include <cmath>
#include <algorithm>
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

// Function to reverse a number
int reverseNumber(int num) 
{
    int reversed = 0;
    while (num > 0) 
    {
        reversed = reversed * 10 + (num % 10);
        num /= 10;
    }
    return reversed;
}

// Function to check if a number is a twisted prime
bool isTwistedPrime(int num) 
{
    if (!isPrime(num)) return false; 
    int reversed = reverseNumber(num); 
    return isPrime(reversed); 
}

int main() 
{
    int num;

    cout << "Enter a number: ";
    cin >> num;

    // Check and display if the number is a twisted prime
    if (isTwistedPrime(num))
        cout << num << " is a Twisted Prime." << endl;
    else
        cout << num << " is NOT a Twisted Prime." << endl;

    return 0;
}
