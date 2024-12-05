#include <iostream>
#include <algorithm>
using namespace std;

int lengthOfLIS(int arr[], int n) 
{
    int dp[n];

    // Initialize all dp values to 1, as each element is a subsequence of length 1
    for (int i = 0; i < n; i++) 
    {
        dp[i] = 1;
    }

    // Fill the dp array using the recurrence relation
    for (int i = 1; i < n; i++) 
    {
        for (int j = 0; j < i; j++) 
        {
            if (arr[i] > arr[j]) 
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    // The result is the maximum value in dp array
    int maxLength = 0;
    for (int i = 0; i < n; i++) 
    {
        maxLength = max(maxLength, dp[i]);
    }

    return maxLength;
}

int main() 
{
    int arr[] = {10, 22, 9, 33, 21, 50, 41, 60, 80};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Length of Longest Increasing Subsequence: " << lengthOfLIS(arr, n) << endl;

    return 0;
}
