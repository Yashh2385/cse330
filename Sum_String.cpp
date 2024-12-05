#include <iostream>
#include <string>
using namespace std;

// Helper function to check if a string can be split into a sum-string
bool checkSumString(string first, string second, string remaining) {
    if (remaining.empty()) {
        return true; // Base case: no remaining string, valid sum-string
    }

    // Calculate the sum of `first` and `second`
    string sum = to_string(stoll(first) + stoll(second));

    // Check if the `remaining` string starts with the calculated sum
    if (remaining.find(sum) != 0) {
        return false; // The sum is not a prefix of the remaining string
    }

    // Recur with new segments
    return checkSumString(second, sum, remaining.substr(sum.length()));
}

// Main function to check if a string is a sum-string
bool isSumString(string S) {
    int n = S.length();

    // Iterate over all possible splits for `first` and `second`
    for (int i = 1; i < n; i++) { // Length of `first`
        for (int j = i + 1; j < n; j++) { // Length of `second`
            string first = S.substr(0, i);
            string second = S.substr(i, j - i);
            string remaining = S.substr(j);

            // Avoid leading zeroes
            if ((first[0] == '0' && first.length() > 1) ||
                (second[0] == '0' && second.length() > 1)) {
                continue;
            }

            // Check if the current split satisfies the sum-string property
            if (checkSumString(first, second, remaining)) {
                return true;
            }
        }
    }

    return false; // No valid sum-string found
}

// Driver code
int main() {
    string S = "12243660";
    if (isSumString(S)) {
        cout << 1 << endl; // Output: 1
    } else {
        cout << 0 << endl; // Output: 0
    }
    return 0;
}
