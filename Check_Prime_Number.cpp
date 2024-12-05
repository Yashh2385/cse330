#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n) 
{
    if (n == 1 || n == 0)
        return false;

    for (int i = 2; i < n; i++) 
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main() 
{
    int N = 192;

    if(isPrime(N)) cout<<"Prime number"<<endl;
    else cout<<"Not prime number"<<endl;
    return 0;
}
