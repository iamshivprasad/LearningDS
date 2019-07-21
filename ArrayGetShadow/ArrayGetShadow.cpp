//Get the shadow
//==============
//Given an unsorted array A[] of size N of positive integers.One number 'a' from set{ 1, 2, …N } is missingand one number 'b' occurs twice in array.The task is to find the repeatingand the missing.
//
//Input:
//The first line of input contains an integer T denoting the number of test cases.The description of T test cases follows.The first line of each test case contains a single integer N denoting the size of array.The second line contains N space - separated integers A1, A2, ..., AN denoting the elements of the array.
//
//Output:
//    For each testcase, in a new line, print b, which is the repeating number, followed by a, which is the missing number, in a single line.
//
//        Constraints :
//        1 ≤ T ≤ 100
//        1 ≤ N ≤ 106
//        1 ≤ A[i] ≤ N
//
//        Example :
//Input:
//    2
//        2
//        2 2
//        3
//        1 3 3
//
//        Output :
//        2 1
//        3 2
//
//        Explanation :
//        Testcase 1 : Repeating number is 2 and smallest positive missing number is 1.
//        Testcase 2 : Repeating number is 3 and smallest positive missing number is 2

#include <iostream>

using namespace std;



void FindShadow()
{

}

int main()
{
    cout << "Enter the size of the array: ";

    int sizeofArray;
    cin >> sizeofArray;

    if (sizeofArray < 1 || sizeofArray > 106)
    {
        cout << "N is not in the permissible limit!";
        return 0;
    }

    int* inputValues = new int[sizeofArray + 1];
    memset(inputValues, 0, sizeof(int) * (sizeofArray + 1));

    cout << "Enter array elements: ";

    int temp = 0;
    int repeated = 0;
    int actualSum = 0;
    for (int i = 1; i <= sizeofArray; ++i)
    {
        cin >> temp;
        actualSum += temp;
        inputValues[temp]++;

        if (inputValues[temp] > 1)
        {
            repeated = temp;
        }
    }

    int sumOfNnumbers = (sizeofArray * (sizeofArray + 1)) / 2;
    int missingNumber = sumOfNnumbers - (actualSum - repeated);

    cout << repeated << " " << missingNumber;

    delete[] inputValues;
    inputValues = nullptr;

    int ch = getchar();
}

