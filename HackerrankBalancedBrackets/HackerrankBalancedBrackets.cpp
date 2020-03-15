// HackerrankBalancedBrackets.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stack>

using namespace std;

bool IsBalanced(string& s)
{
    stack<char> collection;
    for (auto c : s)
    {
        switch (c)
        {
        case '{':
        case '(':
        case '[':
            collection.push(c);
            break;

        case '}':
            {
                if (collection.empty())
                {
                    return false;
                }

                char& top = collection.top();
                if (top == '{')
                {
                    collection.pop();
                }
                else
                    return false;
            }

            break;

        case ')':
            {
                if (collection.empty())
                {
                    return false;
                }

                char& top = collection.top();
                if (top == '(')
                {
                    collection.pop();
                }
                else
                    return false;
            }

            break;

        case ']':
            {
                if (collection.empty())
                {
                    return false;
                }

                char& top = collection.top();
                if (top == '[')
                {
                    collection.pop();
                }
                else
                    return false;
            }
        
            break;
        default:
            return false;
            break;
        }
    }

    if (!collection.empty())
        return false;

    return true;
}

int main()
{
    while (true)
    {
        std::cout << "Enter the string: \n";
        string input;

        cin >> input;

        cout << IsBalanced(input) <<endl;
    }

}

