#include <iostream>
#include <algorithm>
using namespace std;

void subsetSums(int arr[], int n) 
{
    int totalSubsets = 1 << n;  // 2^n subsets
    int sums[totalSubsets]; 
    
    // Generate all subsets and calculate their sums
    for (int i = 0; i < totalSubsets; i++) 
    {
        int sum = 0;
        for (int j = 0; j < n; j++) 
        {
            // If the j-th bit of i is set, include arr[j] in the subset
            if (i & (1 << j)) 
            {
                sum += arr[j];
            }
        }
        sums[i] = sum;
    }
    
    // Sort the sums array in increasing order (Bubble Sort or any other sort)
    for (int i = 0; i < totalSubsets - 1; i++) 
    {
        for (int j = 0; j < totalSubsets - i - 1; j++) 
        {
            if (sums[j] > sums[j + 1]) 
            {
                swap(sums[j], sums[j + 1]);
            }
        }
    }
    
    cout << "Subset sums in increasing order:" << endl;
    for (int i = 0; i < totalSubsets; i++) 
    {
        cout << sums[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {1, 2, 3};  
    int n = sizeof(arr) / sizeof(arr[0]);
    
    subsetSums(arr, n);
    
    return 0;
}
