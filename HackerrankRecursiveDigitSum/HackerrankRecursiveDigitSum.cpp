// HackerrankRecursiveDigitSum.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <fstream>

using namespace std;


// Will time out for bigger inputs
//void digitSum(string num, long& sum)
//{
//    if (num.size() == 0)
//        return;
//    
//    char c = num[num.size() - 1];
//    sum += atoi(&c);
//    num.pop_back();
//    digitSum(num, sum);
//}
//
void digitSum(long long n, long& sum)
{
    if (n < 10)
    {
        sum += n;
        return;
    }

    sum += n % 10;

    digitSum(n / 10, sum);
}


//  (a+b)%x = ((a%x)+(b%x))%x
// http://applet-magic.com/digitsummod9.htm
int superDigit(string n, long k) 
{
    long res = 0;

    for (auto c : n)
    {
        res += atoi(&c) % 9;
    }

    res = res % 9;

    if (res == 0)
        return 9;

    long num = res * k;
    res = 0;

    while (num > 10)
    {
        digitSum(num, res);
        num = res;
        res = 0;
    }

    return num;
}


int main()
{
    int k = 0;
    string number, sk;
    //cin >> number >> k;

    /*superDigit(number, k);*/
    std::ifstream infile("D:\\MyFolder\\DS\\DataStructureSample\\x64\\Debug\\input.txt");
    while (infile >> number >> sk)
    {
        k = atoi(sk.c_str());
    }

    cout << superDigit(number, k) << endl;
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
