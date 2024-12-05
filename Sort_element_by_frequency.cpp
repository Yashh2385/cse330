#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// Function to sort the array by frequency
vector<int> sortByFrequency(const vector<int>& arr) 
{
    // Step 1: Count frequencies
    unordered_map<int, int> frequencyMap;
    for (int num : arr) 
    {
        frequencyMap[num]++;
    }

    // Step 2: Create a vector of pairs (element, frequency)
    vector<pair<int, int>> freqList;
    for (const auto& entry : frequencyMap) 
    {
        freqList.push_back(entry);
    }

    // Step 3: Sort the vector of pairs
    // Sort by frequency (descending), then by element value (ascending)
    sort(freqList.begin(), freqList.end(), [](const pair<int, int>& a, const pair<int, int>& b) 
    {
        if (a.second == b.second) 
        {
            return a.first < b.first; // Sort by value if frequencies are the same
        }
        return a.second > b.second; // Sort by frequency
    });

    // Step 4: Reconstruct the sorted array
    vector<int> sortedArray;
    for (const auto& entry : freqList) 
    {
        sortedArray.insert(sortedArray.end(), entry.second, entry.first);
    }

    return sortedArray;
}

int main() 
{
    vector<int> arr = {4, 4, 3, 2, 3, 1, 2, 2};

    vector<int> sortedArr = sortByFrequency(arr);

    for (int num : sortedArr) 
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}