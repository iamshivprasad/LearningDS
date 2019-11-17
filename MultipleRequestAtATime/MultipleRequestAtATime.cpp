// MultipleRequestAtATime.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>

using namespace std;

void FindMultipleRequestAtATime(string filename)
{

	ifstream fileReader(filename);

	if (fileReader.fail())
	{
		cerr << "Unable to open the file!";
		return;
	}

	string line;

	string dummy;
	string timestamp;
	string timezone;

	unordered_map<string, int> timeStampFreq;

	while (getline(fileReader, line))
	{
		istringstream istream(line);
		istream >> dummy;
		istream >> dummy;
		istream >> dummy;
		istream >> timestamp;
		istream >> timezone;
		istream >> dummy;

		timeStampFreq[timestamp.erase(0, 1) + timezone.erase(timezone.size()-1)]++;
	}

	fileReader.close();

	stringstream outFileNameBuffer;
	outFileNameBuffer << "req_" << filename;
	
	ofstream outputFileStream(outFileNameBuffer.str());
	for (auto& it : timeStampFreq) 
	{
		if (it.second > 1)
		{
			outputFileStream << it.first.substr(0, it.first.find('-')) << endl;
		}
	}

	outputFileStream.flush();
	outputFileStream.close();
}

int main()
{
    std::cout << "Enter the file name!\n";

	string filename;
	cin >> filename;

	FindMultipleRequestAtATime(filename);
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
