#include <iostream>
#include <cmath>
using namespace std;

void sieveOfAtkin(int limit) 
{
    bool isPrime[limit + 1]; 
    for (int i = 0; i <= limit; i++) 
    {
        isPrime[i] = false; 
    }

    // Base cases
    if (limit >= 2) cout << 2 << " ";
    if (limit >= 3) cout << 3 << " ";

    // Step 1: Mark sieve[n] = true if n satisfies any of these conditions
    for (int x = 1; x * x <= limit; x++) 
    {
        for (int y = 1; y * y <= limit; y++) 
        {
            int n = (4 * x * x) + (y * y);
            if (n <= limit && (n % 12 == 1 || n % 12 == 5)) 
            {
                isPrime[n] = !isPrime[n];
            }

            n = (3 * x * x) + (y * y);
            if (n <= limit && n % 12 == 7) 
            {
                isPrime[n] = !isPrime[n];
            }

            n = (3 * x * x) - (y * y);
            if (x > y && n <= limit && n % 12 == 11) 
            {
                isPrime[n] = !isPrime[n];
            }
        }
    }

    // Step 2: Eliminate all squares of primes
    for (int i = 5; i * i <= limit; i++) 
    {
        if (isPrime[i]) 
        {
            for (int j = i * i; j <= limit; j += i * i) 
            {
                isPrime[j] = false;
            }
        }
    }

    // Step 3: Output the primes
    for (int i = 5; i <= limit; i++) 
    {
        if (isPrime[i]) 
        {
            cout << i << " ";
        }
    }
    cout << endl;
}

int main() 
{
    int limit;

    cout << "Enter the upper limit: ";
    cin >> limit;

    // Find and display primes using Sieve of Atkin
    if (limit < 2) 
    {
        cout << "No primes exist below 2." << endl;
    } 
    else 
    {
        sieveOfAtkin(limit);
    }
    return 0;
}
