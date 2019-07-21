// InfixToPostfix.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "../PostfixEvaluationTest/Stack.h"


using namespace std;

int main()
{
    string strInfixExpression = "";
    std::cout << "Enter the infix expression";

    Stack<char> oprStack;
    Stack<char> postfixStack;

    for(char& c : strInfixExpression )
    {
        if (isdigit(c))
        {
            postfixStack.Push(c);
        }
        else
        {
            switch (c)
            {
            case '*':
            case '/':
            {
                if (oprStack.IsEmpty())
                {
                    oprStack.Push(c);
                }
                else
                {
                    char c = oprStack.Pop();
                    if (c != '+' && c != '-')
                    {
                        postfixStack.Push(c);
                    }
                }
                break;
            }
            case '+':
            case '-':
                oprStack.Push(c);


            default:
                break;
            }

        }
    }

}
