#include <iostream>
using namespace std;

void printLexicographicalOrder(int n, int current) 
{
    // If the current number exceeds n, return
    if (current > n) 
    {
        return;
    }
    
    // Print the current number
    cout << current << " ";
    
    // Recursively try to append digits to the current number
    for (int i = 0; i <= 9; i++) 
    {
        if (current * 10 + i <= n) 
        {
            printLexicographicalOrder(n, current * 10 + i);
        }
    }
}

int main() {
    int n;
    cout << "Enter a number n: ";
    cin >> n;
    
    for (int i = 1; i <= 9; i++) 
    {
        if (i <= n) 
        {
            printLexicographicalOrder(n, i);
        }
    }
    
    return 0;
}
