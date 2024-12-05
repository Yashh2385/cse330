#include <iostream>
#include <algorithm>
using namespace std;

int findUnsortedSubarray(int nums[], int n) 
{
    int* res = new int[n];
    for (int i = 0; i < n; i++) 
    {
        res[i] = nums[i];
    }
    
    sort(res, res + n);

    int rStart = -1, rEnd = -1;
    
    // Find the first index where elements differ
    for (int i = 0; i < n; i++) 
    {
        if (nums[i] != res[i]) 
        {
            if (rStart == -1) rStart = i;  
            rEnd = i;  
        }
    }

    // If the array is already sorted
    if (rStart == -1) 
    {
        delete[] res;  // Free dynamically allocated memory
        return 0;
    }

    delete[] res;  
    return rEnd - rStart + 1;
}

int main() 
{
    int nums[] = {2, 6, 4, 8, 10, 9, 15};
    int n = sizeof(nums) / sizeof(nums[0]);
    cout << findUnsortedSubarray(nums, n) << endl; 
    return 0;
}
