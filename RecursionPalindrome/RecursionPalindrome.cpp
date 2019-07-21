// RecursionPalindrome.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

bool IsPalindrome(char* input, int front, int back)
{
    if (front == back)
    {
        return true;
    }

    if (input[front] != input[back])
    {
        return false;
    }

    if (front < back)
        return IsPalindrome(input, front + 1, back - 1);

    return true;
}

int main()
{
    std::cout << "Enter a word:";

    char input[10];
    cin >> input;

    if (IsPalindrome(input, 0, 9))
    {
        cout << "Palindrome!";
    }
    else
    {
        cout << "Not Palindrome!";

    }
}
