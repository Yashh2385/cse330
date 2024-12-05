#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string caseSpecificSort(const string &str) 
{
    vector<char> upperChars;
    vector<char> lowerChars;

    for (char ch : str) 
    {
        if (isupper(ch)) 
        {
            upperChars.push_back(ch);
        } 
        else if (islower(ch)) 
        {
            lowerChars.push_back(ch);
        }
    }

    sort(upperChars.begin(), upperChars.end());
    sort(lowerChars.begin(), lowerChars.end());

    string result = "";
    for (char ch : upperChars) 
    {
        result += ch;
    }
    for (char ch : lowerChars) 
    {
        result += ch;
    }

    return result;
}

int main() {
    string str = "aBzDk";
    
    string sortedStr = caseSpecificSort(str);
    
    cout << "Original string: " << str << endl;
    cout << "Sorted string: " << sortedStr << endl;

    return 0;
}
