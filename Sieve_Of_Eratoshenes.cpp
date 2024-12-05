#include <iostream>
using namespace std;

void sieveOfEratosthenes(int n) 
{
    bool isPrime[n + 1];

    // Initialize all elements to true
    for (int i = 0; i <= n; i++) 
    {
        isPrime[i] = true;
    }

    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i <= n; i++) 
    {
        if (isPrime[i]) 
        {
            for (int j = i * i; j <= n; j += i) 
            {
                isPrime[j] = false;
            }
        }
    }

    for (int i = 2; i <= n; i++)
     {
        if (isPrime[i]) 
        {
            cout << i << " ";
        }
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    cout << "Prime numbers up to " << n << " are: ";
    sieveOfEratosthenes(n);

    return 0;
}
