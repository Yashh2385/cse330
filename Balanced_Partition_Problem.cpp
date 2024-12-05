#include <iostream>
#include <algorithm>
using namespace std;

bool canPartition(int arr[], int n) {
    int totalSum = 0;
    
    // Calculate the total sum of the array
    for (int i = 0; i < n; i++) {
        totalSum += arr[i];
    }

    // If the sum is odd, it cannot be partitioned into two equal subsets
    if (totalSum % 2 != 0) {
        return false;
    }

    // Target sum for each subset
    int target = totalSum / 2;

    // DP table to store the results of subproblems
    bool dp[target + 1] = {false};

    // Base case: A sum of 0 is always possible (with an empty subset)
    dp[0] = true;

    // Fill the DP table
    for (int i = 0; i < n; i++) {
        for (int j = target; j >= arr[i]; j--) {
            dp[j] = dp[j] || dp[j - arr[i]];
        }
    }

    // The result will be in dp[target]
    return dp[target];
}

int main() {
    int arr[] = {1, 5, 11, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    if (canPartition(arr, n)) {
        cout << "The array can be partitioned into two subsets with equal sum." << endl;
    } else {
        cout << "The array cannot be partitioned into two subsets with equal sum." << endl;
    }

    return 0;
}
