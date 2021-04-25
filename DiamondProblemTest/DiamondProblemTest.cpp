// DiamondProblemTest.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//#include <iostream>
//
//using namespace std;
//
//class A
//{
//public:
//    virtual void display()
//    {
//        cout << "Inside A" << endl;
//    }
//};
//
//class B : virtual public A
//{
//public:
//    virtual void display()
//    {
//        cout << "Inside B" << endl;
//    }
//};
//
//class C : virtual public A
//{
//
//};
//
//class D : public B, public C
//{
//
//};
//
//int main()
//{
//    std::cout << "Hello World!\n";
//    D d;
//    d.B::display();
//}


//#include <windows.h>
//
//#include <stdio.h>
//
//volatile LONG TotalThreadCount = 0;
//
//////// Thread Main /////////
//
//void ThreadMain(void)
//
//{
//    DWORD dwIncre = 0, dwDecre = 0;
//    for (;;)
//    {
//        //dwIncre = InterlockedIncrement((LPLONG)&TotalThreadCount);
//        ++TotalThreadCount;
//        wprintf(L"InterlockedIncrement() - Increment value is % u\n", TotalThreadCount);
//
//        Sleep(100);
//
//        //dwDecre = InterlockedDecrement((LPLONG)&TotalThreadCount);
//        --TotalThreadCount;
//
//        wprintf(L"InterlockedDecrement() - Decrement value is % u\n", TotalThreadCount);
//    }
//
//}
//
/////////// Create A Child //////////////
//
//void CreateChildThread(void)
//{
//    HANDLE hThread;
//    DWORD dwId;
//    hThread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)ThreadMain, (LPVOID)NULL, 0, &dwId);
//    if (hThread != NULL)
//        wprintf(L"CreateThread() is OK, thread ID is % u\n", dwId);
//    else
//        wprintf(L"CreateThread() failed, error % u\n", GetLastError());
//    wprintf(L"\n");
//
//    if (CloseHandle(hThread) != 0)
//        wprintf(L"hThread's handle closed successfully!\n");
//    else
//            wprintf(L"Failed to close hThread's handle, error %u\n", GetLastError());
//
//    wprintf(L"\n");
//
//}
//
//
//
/////// Main ////////
//
//int wmain(void)
//
//{
//    DWORD Count;
//
//    CreateChildThread();
//
//    CreateChildThread();
//
//    CreateChildThread();
//
//
//    for (Count = 0; Count < 5; Count++)
//    {
//        wprintf(L"Total number of threads in critical section = % u\n", TotalThreadCount);
//    }
//
//    getchar();
//
//    return 0;
//}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
