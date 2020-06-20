// SerializeBT.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <map>

using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

void inorder(const Node* head, fstream& fs)
{
    if (head == nullptr)
        return;

    inorder(head->left, fs);

    fs << head->data << " ";
    cout << head->data << " ";

    inorder(head->right, fs);
}

void preorder(const Node* head, fstream& fs)
{
    if (head == nullptr)
        return;

    fs << head->data << " ";
    cout << head->data << " ";

    preorder(head->left, fs);
    preorder(head->right, fs);
}

void readFile(string file, vector<int>& arr)
{
    fstream fs;
    fs.open(file, fstream::in);

    string line;
    if (fs.is_open())
    {
        while (getline(fs, line))
        {
            stringstream ss(line);

            while (!ss.eof())
            {
                int t;
                ss >> t;

                arr.push_back(t);
            }
        }
    }

    fs.close();
}

Node* buildTree(map<int, int>& in_map, vector<int>& pre_arr,
    int start, int end, int& preIdx)
{
    if (start > end)
    {
        return nullptr;
    }

    Node* newNode = new Node();
    newNode->data = pre_arr[preIdx++];

    if (start == end)
    {
        return newNode;
    }

    int inIdx = in_map[newNode->data];

    newNode->left = buildTree(in_map, pre_arr, start, inIdx - 1, preIdx);
    newNode->right = buildTree(in_map, pre_arr, inIdx + 1, end, preIdx);

    return newNode;
}

Node* Deserialize(const string& inorder, const string& preorder)
{
    vector<int> in_arr;
    readFile(inorder, in_arr);

    vector<int> pre_arr;
    readFile(preorder, pre_arr);

    map<int, int> in_map;

    for (int i = 0; i<in_arr.size();++i)
    {
        in_map[in_arr[i]] = i;
    }

    int i = 0;
    return buildTree(in_map, pre_arr,  0, in_arr.size()-1, i);
}

int main()
{
    //fstream fs;

    //Node* head = new Node();
    //head->data = 2;

    //Node* three = new Node();
    //three->data = 3;
    //head->left = three;

    //Node* four = new Node();
    //four->data = 4;
    //head->right = four;

    //Node* five = new Node();
    //five->data = 5;
    //three->left = five;

    //Node* six = new Node();
    //six->data = 6;
    //three->right = six;

    //Node* seven = new Node();
    //seven->data = 7;
    //four->left = seven;


    //fs.open("inorder.txt", fstream::out);
    //inorder(head, fs);
    //fs.flush();
    //fs.close();

    //fs.open("preorder.txt", fstream::out);
    //preorder(head, fs);
    //fs.flush();
    //fs.close();


    //Node* t = Deserialize("inorder.txt", "preorder.txt");


    // delete all the pointers

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
