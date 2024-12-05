#include <iostream>
using namespace std;

void merge(int arr[], int left, int mid, int right) 
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int leftArr[n1], rightArr[n2];

    for (int i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        rightArr[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) 
    {
        if (leftArr[i] <= rightArr[j]) 
        {
            arr[k] = leftArr[i];
            i++;
        } 
        else 
        {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements of leftArr[], if any
    while (i < n1) 
    {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    // Copy remaining elements of rightArr[], if any
    while (j < n2) 
    {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int n) 
{
    // Start with subarrays of size 1, then 2, 4, 8, etc.
    for (int currSize = 1; currSize < n; currSize *= 2) 
    {
        // Pick starting point of left subarray
        for (int left = 0; left < n - currSize; left += 2 * currSize) 
        {
            // Find mid and right for current subarray
            int mid = left + currSize - 1;
            int right = min(left + 2 * currSize - 1, n - 1);

            merge(arr, left, mid, right);
        }
    }
}

void printArray(int arr[], int size) 
{
    for (int i = 0; i < size; i++) 
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() 
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, n);

    mergeSort(arr, n);

    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}
