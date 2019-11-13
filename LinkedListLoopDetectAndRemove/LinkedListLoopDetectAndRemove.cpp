// LinkedListLoopDetectAndRemove.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "..\LinkedList\List.h"

int main()
{

	// 2 -> 4 -> 6 -> 10
	// 1 -> 3 -> 5 -> 7 -> 11

	Node* lfirst = new Node();
	lfirst->m_Value = 2;
	
	Node* lsecond = new Node();
	lsecond->m_Value = 4;

	Node* lthird = new Node();
	lthird->m_Value = 6;

	Node* lfourth = new Node();
	lfourth->m_Value = 10;
//////////////////////////////////////

	Node* rfirst = new Node();
	rfirst->m_Value = 1;

	Node* rsecond = new Node();
	rsecond->m_Value = 3;

	Node* rthird = new Node();
	rthird->m_Value = 5;

	Node* rfourth = new Node();
	rfourth->m_Value = 7;

	Node* rfifth = new Node();
	rfifth->m_Value = 11;
/////////////////////////////////////
	
	lfirst->m_pNext = lsecond;
	lsecond->m_pNext = lthird;
	lthird->m_pNext = lfourth;
	lfourth->m_pNext = nullptr;

	rfirst->m_pNext = rsecond;
	rsecond->m_pNext = rthird;
	rthird->m_pNext = rfourth;
	rfourth->m_pNext = rfifth;
	rfifth->m_pNext = nullptr;
	
	Node* lHead = lfirst;
	Node* rHead = rfirst;

	Node* merged = List::SortedMerge(lHead, rHead);

	return 0;
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
