#include <iostream>

#include "HashTable.h"

using namespace std;

int main(int argc, char* argv[])
{
    HashTable<int> table;
    table.insert(25);
    table.insert(5);
    table.insert(15);

    return 0;

}