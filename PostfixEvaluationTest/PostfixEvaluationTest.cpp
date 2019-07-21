// PostfixEvaluationTest.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "Stack.h"

using namespace std;

double division(int a, int b) {
    if (b == 0) {
        throw "Division by zero condition!";
    }
    cout << "1";
    cout << "2";

    return 0;
}

int main()
{

    string strInfixExpression = "";

    std::cout << "Enter the postfix expression:\n";
    cin >> strInfixExpression;

    Stack<char> evalStack;

    bool bIsInvalid = false;

    for (char& c : strInfixExpression)
    {
        if (isdigit(c))
        {
            evalStack.Push(c - '0');
        }
        else
        {
            switch (c)
            {
                case '+':
                {
                    try
                    {
                        int nOp2 = evalStack.Pop();
                        int nOp1 = evalStack.Pop();

                        evalStack.Push(nOp1 + nOp2);
                    }
                    catch (const std::exception&)
                    {
                        cout << "Not a valid postfix expression";
                        bIsInvalid = true;
                    }
                    break;
                }

                case '-':
                {
                    int nOp2 = evalStack.Pop();
                    int nOp1 = evalStack.Pop();

                    evalStack.Push(nOp2 - nOp1);
                    break;
                }

                case '*':
                {
                    int nOp2 = evalStack.Pop();
                    int nOp1 = evalStack.Pop();

                    evalStack.Push(nOp2 * nOp1);
                    break;
                }
                case '/':
                {
                    int nOp2 = evalStack.Pop();
                    int nOp1 = evalStack.Pop();

                    evalStack.Push(nOp1 / nOp2);
                    break;
                }
                default:
                    break;
            }

            if (bIsInvalid)
            {
                break;
            }
        }
    }


}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
