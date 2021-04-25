// TinyURL.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <unordered_map>
#include <sstream>

using namespace std;

class Solution {
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) 
    {
        while(m_url_code_table.find(longUrl) == m_url_code_table.end())
        {
            stringstream buf;
            for (int i = 0; i < 6; ++i)
            {
                buf << charset[rand() % charset.size()];
            }

            string code = buf.str();
            if (!m_code_url_table.count(code))
            {
                m_code_url_table[code] = longUrl;
                m_url_code_table[longUrl] = code;
            }
        }

        auto code = m_url_code_table[longUrl];
        return "http://www.tinyurl.com/" + code;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) 
    {
        auto pos = shortUrl.find_last_of("/");

        auto itr = m_code_url_table.find(shortUrl.substr(pos + 1));

        if (itr == m_code_url_table.end())
            return "";

        return itr->second;
    }

private:

    const string charset = "abcdefghABCDEFGH0123456789";

    unordered_map<string, string> m_url_code_table;
    unordered_map<string, string> m_code_url_table;
};



int main()
{
    std::cout << "Hello World!\n";

    Solution obj;
    auto tiny = obj.encode("www.linkedin.com/in/sivaprasad-tr");

    cout << "Encoded : " << tiny << endl;

    string original = obj.decode(tiny);
    cout << "Decoded : " << original;
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
