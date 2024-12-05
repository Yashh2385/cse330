#include <bits/stdc++.h>
using namespace std;

const int MAX_CHAR = 26;

void sortString(string s) 
{ 
    // Count array to keep count of characters
    int charCount[MAX_CHAR] = {0};
    
    // Traverse string and increment count of characters
    for (int i = 0; i < s.length(); i++) 
    {
        // 'a'-'a' will be 0, 'b'-'a' will be 1, etc.
        charCount[s[i] - 'a']++;
    }
    
    for (int i = 0; i < MAX_CHAR; i++) 
    {
        for (int j = 0; j < charCount[i]; j++) 
        {
            cout << (char)('a' + i);
        }
    }
}

int main() 
{
    string s = "geeksforgekcccs";    
    sortString(s);    
    return 0;
}