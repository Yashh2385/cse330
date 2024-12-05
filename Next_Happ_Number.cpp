#include <iostream>
using namespace std;

// Function to calculate sum of squares of digits of a number
int sumOfSquares(int num) 
{
    int sum = 0;
    while (num > 0) 
    {
        int digit = num % 10;
        sum += digit * digit;
        num /= 10;
    }
    return sum;
}

// Function to check if a number is a happy number
bool isHappy(int num) 
{
    // Use a set to detect cycles
    while (num != 1 && num != 4) // 4 is a known non-happy cycle
    { 
        num = sumOfSquares(num);
    }
    return num == 1;
}

// Function to find the next happy number after the given number
int nextHappyNumber(int num) 
{
    num++;
    while (!isHappy(num)) 
    {
        num++;
    }
    return num;
}

int main() 
{
    int num;
    cout << "Enter a number: ";
    cin >> num;

    int nextHappy = nextHappyNumber(num);
    cout << "The next happy number after " << num << " is: " << nextHappy << endl;

    return 0;
}
