#include <iostream>
#include <cmath>
using namespace std;

// This function finds all primes smaller than 'limit'
// using simple sieve of Eratosthenes.
void simpleSieve(int limit, bool prime[], int primeArray[])
{
    // Create a boolean array "mark[0..n-1]" and initialize
    // all entries of it as true. A value in mark[p] will
    // finally be false if 'p' is not a prime, else true.
    for (int i = 0; i <= limit; i++) {
        prime[i] = true;
    }
    prime[0] = prime[1] = false;  // 0 and 1 are not primes

    for (int p = 2; p * p <= limit; p++) {
        if (prime[p] == true) {
            for (int i = p * p; i <= limit; i += p)
                prime[i] = false;
        }
    }

    // Store found primes in primeArray
    int index = 0;
    for (int p = 2; p <= limit; p++) {
        if (prime[p]) {
            primeArray[index++] = p;
        }
    }
}

// Prints all prime numbers smaller than 'n'
void segmentedSieve(int n)
{
    // Compute all primes smaller than or equal to
    // square root of n using simple sieve
    int limit = floor(sqrt(n)) + 1;
    bool prime[limit + 1];
    int primeArray[limit];  // Array to store primes up to sqrt(n)
    simpleSieve(limit, prime, primeArray);

    // Divide the range [0..n-1] into different segments
    int low = limit;
    int high = 2 * limit;

    // Process all segments of range [0..n-1]
    while (low < n)
    {
        if (high >= n)
            high = n;

        bool mark[high - low];
        for (int i = 0; i < high - low; i++) {
            mark[i] = true;  // Assume all numbers in range [low, high] are prime
        }

        // Use the found primes by simpleSieve() to find
        // primes in the current range
        for (int i = 0; primeArray[i] * primeArray[i] <= high; i++)
        {
            int currentPrime = primeArray[i];
            // Find the minimum number in [low..high] that is
            // a multiple of prime[i]
            int loLim = max(currentPrime * currentPrime, (low + currentPrime - 1) / currentPrime * currentPrime);
            
            // Mark all multiples of currentPrime as false
            for (int j = loLim; j < high; j += currentPrime)
                mark[j - low] = false;
        }

        // Print primes in the current range
        for (int i = low; i < high; i++)
            if (mark[i - low])
                cout << i << " ";

        // Update low and high for the next segment
        low = low + limit;
        high = high + limit;
    }
}

// Driver program to test above function
int main()
{
    int n = 100;
    cout << "Primes smaller than " << n << ":\n";
    segmentedSieve(n);
    return 0;
}
