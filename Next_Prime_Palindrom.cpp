#include <iostream>
#include <cmath>
using namespace std;

// Function to check if a number is prime
bool isPrime(int num) 
{
    if (num <= 1) return false;
    if (num == 2) return true;
    if (num % 2 == 0) return false;

    for (int i = 3; i * i <= num; i += 2) 
    {
        if (num % i == 0) 
        {
            return false;
        }
    }
    return true;
}

// Function to find the next prime greater than n
int nextPrime(int n) 
{
    int num = n + 1;
    while (!isPrime(num)) 
    {
        num++;
    }
    return num;
}

// Function to check if a number is palindrome
bool isPalindrome(int num) 
{
    int original = num, reversed = 0, remainder;
    
    while (num != 0)
    {
        remainder = num % 10;
        reversed = reversed * 10 + remainder;
        num /= 10;
    }

    return original == reversed;
}

int main() 
{
    int n;
    cout << "Enter a number: ";
    cin >> n;

    int next_prime = nextPrime(n);
    cout << "The next prime number after " << n << " is: " << next_prime << endl;

    if (isPalindrome(next_prime)) 
    {
        cout << next_prime << " is a palindrome." << endl;
    } 
    else 
    {
        cout << next_prime << " is not a palindrome." << endl;
    }

    return 0;
}
