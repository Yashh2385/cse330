#include<iostream>
#include<unordered_set>
using namespace std;

int sumOfSquares(int n) 
{
    int sum = 0;
    while (n > 0) 
    {
        int digit = n % 10;  
        sum += digit * digit;  
        n /= 10;  
    }
    return sum;
}

bool isHappy(int n) 
{
    unordered_set<int> seenNumbers;  
    
    while (n != 1 && seenNumbers.find(n) == seenNumbers.end()) 
    {
        seenNumbers.insert(n);  // Add the current number to the set
        n = sumOfSquares(n);  // Update n to the sum of squares of its digits
    }
    
    return n == 1;
}

int main() 
{
    int num;
    cout << "Enter a number: ";
    cin >> num;
    
    if (isHappy(num)) 
    {
        cout << num << " is a Happy Number!" << endl;
    } 
    else 
    {
        cout << num << " is not a Happy Number!" << endl;
    }
    
    return 0;
}
