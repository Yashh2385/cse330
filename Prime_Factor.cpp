#include <iostream>
using namespace std;

void findPrimeFactors(int n) 
{
    cout << "Prime factors of " << n << " are: ";

    // Handle the number of 2s in n
    while (n % 2 == 0) 
    {
        cout << 2 << " ";
        n /= 2;
    }

    // Handle odd factors
    for (int i = 3; i * i <= n; i += 2) 
    {
        while (n % i == 0) 
        {
            cout << i << " ";
            n /= i;
        }
    }

    // If n is a prime number greater than 2
    if (n > 2) {
        cout << n;
    }
    cout << endl;
}

int main() 
{
    int num;

    cout << "Enter a number: ";
    cin >> num;

    if (num <= 1) 
    {
        cout << "Number must be greater than 1." << endl;
        return 0;
    }

    findPrimeFactors(num);

    return 0;
}
