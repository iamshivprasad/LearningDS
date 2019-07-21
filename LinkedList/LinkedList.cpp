// LinkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "List.h"

int main()
{
    int isContinue = 1;

    List myList;
    int n;

    while (isContinue)
    {
        std::cout << "Enter an element: \n";
        std::cin >> n;

        //myList.Add(n);
        myList.InsertInFront(n);

        std::cout << "Do you want to enter another element: \n";
        std::cin >> isContinue;
    }

    std::cout << "Inserting elements: \n";

    myList.ReverseByIteration();

    myList.Display();

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
