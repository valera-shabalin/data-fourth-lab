#include <iostream>

#include "Tree.h"

using namespace std;

int main() 
{
    setlocale(LC_CTYPE, "Rus");

    Tree t = Tree();

    t.InsertNode(4).InsertNode(6).InsertNode(10).InsertNode(1);


    cout << t;
    
}

