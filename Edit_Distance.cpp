#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int editDistance(string s1, string s2) 
{
    int m = s1.length();
    int n = s2.length();

    int dp[m + 1][n + 1];

    for (int i = 0; i <= m; i++) 
    {
        for (int j = 0; j <= n; j++) 
        {
            if (i == 0) 
            {
                dp[i][j] = j; // All insertions
            } 
            else if (j == 0) 
            {
                dp[i][j] = i; // All deletions
            } 
            else if (s1[i - 1] == s2[j - 1]) 
            {
                dp[i][j] = dp[i - 1][j - 1]; // Characters match
            } 
            else 
            {
                dp[i][j] = 1 + min({dp[i - 1][j],     // Remove
                                    dp[i][j - 1],     // Insert
                                    dp[i - 1][j - 1]  // Replace
                                   });
            }
        }
    }

    return dp[m][n];
}

int main() 
{
    string s1, s2;
    cout << "Enter the first string: ";
    cin >> s1;
    cout << "Enter the second string: ";
    cin >> s2;

    cout << "The minimum edit distance is: " << editDistance(s1, s2) << endl;

    return 0;
}
