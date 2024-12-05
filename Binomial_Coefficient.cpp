#include <iostream>
using namespace std;

int binomialCoefficient(int n, int r) 
{
    if (r > n) return 0;

    int dp[r + 1] = {0};
    dp[0] = 1; 

    
    for (int i = 1; i <= n; ++i) 
    {
        for (int j = min(i, r); j > 0; --j) 
        {
            dp[j] = dp[j] + dp[j - 1];
        }
    }

    return dp[r];
}

int main() 
{
    int n, r;
    cout << "Enter values of n and r: ";
    cin >> n >> r;

    cout << "Binomial Coefficient C(" << n << ", " << r << ") = " << binomialCoefficient(n, r) << endl;

    return 0;
}
