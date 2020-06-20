// GraphTheory.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#define I INT_MAX

using namespace std;

void primsMst(int cost[][8])
{

}

int main()
{
	int cost[][8] =
	{
		{I,I,I,I,I,I,I,I},
		{I,I,25,I,I,I,15,I},
		{I,25,I,12,I,I,I,10},
		{I,I,12,I,8,I,I,I},
		{I,I,I,8,I,16,I,14},
		{I,I,I,I,16,I,20,18},
		{I,5,I,I,I,20,I,I},
		{I,I,10,I,14,18,I,I}
	};


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
