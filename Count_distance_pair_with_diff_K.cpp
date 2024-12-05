#include <iostream>
#include <cmath> 
using namespace std;

int countPairs(int arr[], int n, int k) 
{
    int cnt = 0;

    for (int i = 0; i < n; i++) 
    {
        for (int j = i + 1; j < n; j++) 
        {
            
            if (abs(arr[i] - arr[j]) == k) 
            {
                cnt += 1;
            }
        }
    }
    return cnt;
}

int main() 
{
    int arr[] = {1, 4, 1, 4, 5}; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    int k = 3; 

    cout << "Number of pairs with difference " << k << ": " << countPairs(arr, n, k);
    return 0;
}
