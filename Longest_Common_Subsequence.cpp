#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int LCS(string X, string Y) 
{
    int m = X.length();
    int n = Y.length();

    int dp[m + 1][n + 1];

    // Fill the DP table
    for (int i = 0; i <= m; i++) 
    {
        for (int j = 0; j <= n; j++) 
        {
            if (i == 0 || j == 0) 
            {
                // Base case: LCS with an empty string is 0
                dp[i][j] = 0;  
            } 
            else if (X[i - 1] == Y[j - 1]) 
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;  // Characters match
            } 
            else 
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);  // No match, take max
            }
        }
    }

    return dp[m][n];
}

int main() 
{
    string X = "AGGTAB";
    string Y = "GXTXAYB";

    cout << "Length of Longest Common Subsequence: " << LCS(X, Y) << endl;

    return 0;
}
